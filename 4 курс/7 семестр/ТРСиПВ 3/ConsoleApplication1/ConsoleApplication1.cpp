#include <iostream>
#include <iomanip>
#include <mpi.h>

using namespace std;

const int N = 4;
const int NUM_DIMS = 1;

void showRow(int row[N]);
void showMatrix(int matrix[][N], string title);

int main(int argc, char* argv[])
{
	int rank, processes;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &processes);
	MPI_Comm comm_cart;
	MPI_Status status;

	int masterProcess = 0;
	int dims[NUM_DIMS];
	int periods[NUM_DIMS], source, dest;
	int reorder = 0;

	int A[N][N];
	int B[N][N];
	int C[N][N];
	int rowA[N], rowB[N], rowC[N];
	int columnIndex = rank;

	// Обнуляем массив dims и заполняем массив periods для топологии "кольцо"
	for (int i = 0; i < NUM_DIMS; i++)
	{
		dims[i] = 0; periods[i] = 1;
	}

	// Заполняем массив dims, где указываются размеры (одномерной) решетки
	MPI_Dims_create(processes, NUM_DIMS, dims);

	// Создаем топологию "кольцо" с communicator(ом) comm_cart
	MPI_Cart_create(MPI_COMM_WORLD, NUM_DIMS, dims, periods, reorder, &comm_cart);

	// Каждая ветвь находит своих соседей вдоль кольца, в направлении больших значений рангов
	MPI_Cart_shift(comm_cart, 0, 1, &source, &dest);

	if (rank == masterProcess)
	{
		int dataA[N][N] = {
			{23, 93, 67, 35},
			{90, 20, 55, 68},
			{14, 96, 39, 66},
			{44, 26, 88, 25},
		};

		int dataB[N][N] = {
			{58, 66, 32, 12},
			{44, 79, 16, 65},
			{98, 31, 90, 73},
			{27, 32, 66, 39},
		};

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				A[i][j] = dataA[i][j];
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				B[i][j] = dataB[j][i];
			}
		}

		showMatrix(A, "First:");
		showMatrix(B, "Second:");
	}

	// Разрезаем матрицы на строки и столбцы и передаем во все процессы для обработки
	MPI_Scatter(A, 4, MPI_INT, rowA, 4, MPI_INT, masterProcess, MPI_COMM_WORLD);
	MPI_Scatter(B, 4, MPI_INT, rowB, 4, MPI_INT, masterProcess, MPI_COMM_WORLD);

	// Производим вычисления
	for (int i = 0; i < N; i++)
	{
		rowC[columnIndex] = 0;
		for (int j = 0; j < N; j++)
		{
			rowC[columnIndex] += rowA[j] * rowB[j];
		}

		cout << "Process " << rank << " : ";
		showRow(rowA);
		cout << "-- ";
		showRow(rowB);
		cout << "-- " << rowC[columnIndex] << " -- " << rank << ":" << columnIndex << endl;

		// Отправляем по кольцу следующий индекс столбца B
		MPI_Send(&columnIndex, 1, MPI_INT, dest, 12, comm_cart);
		MPI_Recv(&columnIndex, 1, MPI_INT, source, 12, comm_cart, &status);

		// Отправляем по кольцу сам столбец B
		MPI_Send(&rowB, N, MPI_INT, dest, 12, comm_cart);
		MPI_Recv(&rowB, N, MPI_INT, source, 12, comm_cart, &status);
	}

	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Barrier(comm_cart);

	MPI_Gather(rowC, N, MPI_INT, C, N, MPI_INT, masterProcess, MPI_COMM_WORLD);

	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Barrier(comm_cart);

	if (rank == masterProcess) {
		showMatrix(C, "Result:");
	}

	// Все ветви завершают системные процессы, связанные с топологией comm_cart и завершают выполнение программы
	MPI_Comm_free(&comm_cart);
	MPI_Finalize();

	return 0;
}

void showRow(int row[N])
{
	for (int i = 0; i < N; i++)
	{
		cout << row[i] << " ";
	}
}

void showMatrix(int matrix[][N], string title)
{
	cout << endl << title << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}