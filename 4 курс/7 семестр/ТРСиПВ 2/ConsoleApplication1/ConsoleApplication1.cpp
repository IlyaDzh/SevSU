#include <iostream>
#include <fstream>
#include "mpi.h"

using namespace std;

double** InitMatrix(int row, int column);
double** ReadMatrixFromFile(string path, int* row, int* column);
void PrintMatrix(double** matrix, int row, int column);
double* fromMatrixToVector(double** matrix, int row, int column);
double** fromVectorToMatrix(double* vector, int row, int column);
double* MatrixMultyply(double** partMatrixA, int rowA, int columnA, double** matrixB, int rowB, int columnB);
double* MultiplyRowsByColumn(double* vectorA, double** matrixB, int vector_column, int matrix_column);

int main(int argc, char* argv[])
{
	int rowA = 8, columnA = 5, rowB = 5, columnB = 3, buffSize = 5 * 3;

	MPI_Status status;
	int rank, size, i = 0, k = 2;
	double** matrixA, ** matrixB, * buffer = new double[buffSize];
	double* mainResult = new double[rowA * columnB];
	double* partResult = new double[k * columnB];
	double* vectorToSend = new double[(rowA / k) * columnA * k];
	double* recvBuffer = new double[k * columnA];

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0) {
		// 1) рассылаем matrixA по 2 строки по процессам
		matrixA = ReadMatrixFromFile("matrixA.txt", &rowA, &columnA);
		cout << "Matrix A:" << endl;
		PrintMatrix(matrixA, rowA, columnA);

		// создаем из каждых двух строк матрицы один вектор
		double** matrixToSender = InitMatrix(rowA / k, columnA * k);
		for (int i = 0, number = 0; i < rowA; number++) {
			double** temp = InitMatrix(k, columnA);
			for (int j = 0; j < k; j++) {
				temp[j] = matrixA[i++];
			}
			matrixToSender[number] = fromMatrixToVector(temp, k, columnA);
		}
		vectorToSend = fromMatrixToVector(matrixToSender, rowA / k, columnA * k);

		// создаем из матрицы matrixB вектор buffer
		matrixB = ReadMatrixFromFile("matrixB.txt", &rowB, &columnB);
		cout << "Matrix B: " << endl;
		PrintMatrix(matrixB, rowB, columnB);

		buffer = fromMatrixToVector(matrixB, rowB, columnB);
	}

	// отправляем каждому процессу свою часть матрицы А в виде вектора
	MPI_Scatter(vectorToSend, k * columnA, MPI_DOUBLE, recvBuffer, k * columnA, MPI_DOUBLE, 0, MPI_COMM_WORLD);

	// 2) рассылаем matrixB по всем процессам
	MPI_Bcast(buffer, buffSize, MPI_DOUBLE, 0, MPI_COMM_WORLD);

	// 3) в каждом процессе получаем свою часть матрицы А и всю матрицу В в виде векторов
	double** partMatrixA = fromVectorToMatrix(recvBuffer, k, columnA);
	matrixB = fromVectorToMatrix(buffer, rowB, columnB);

	partResult = MatrixMultyply(partMatrixA, k, columnA, matrixB, rowB, columnB);
	cout << "Result of matrix multiplication: " << endl;
	PrintMatrix(fromVectorToMatrix(partResult, k, columnB), k, columnB);

	// 4) собираем результат умножения со всех процессов
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Gather(partResult, k * columnB, MPI_DOUBLE, mainResult, k * columnB, MPI_DOUBLE, 0, MPI_COMM_WORLD);

	if (rank == 0) {
		cout << "Result: " << endl;
		PrintMatrix(fromVectorToMatrix(mainResult, rowA, columnB), rowA, columnB);
	}

	MPI_Finalize();

	return 0;
}

double** InitMatrix(int row, int column) {
	double** matrix = new double* [row];
	for (int i = 0; i < row; i++) {
		matrix[i] = new double[column];
	}
	return matrix;
}

double** ReadMatrixFromFile(string path, int* row, int* column) {
	ifstream in(path);
	double** matrix;

	if (in.is_open()) {
		in >> *row >> *column;

		matrix = InitMatrix(*row, *column);

		for (int i = 0; i < *row; i++) {
			for (int j = 0; j < *column; j++) {
				in >> matrix[i][j];
			}
		}

		in.close();
		return matrix;
	}
	else {
		cout << "Файл не найден!";
		return 0;
	}
}

void PrintMatrix(double** matrix, int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

double* fromMatrixToVector(double** matrix, int row, int column) {
	double* buffer = new double[row * column];
	int k = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++, k++) {
			buffer[k] = matrix[i][j];
		}
	}
	return buffer;
}


double** fromVectorToMatrix(double* vector, int row, int column) {
	double** result_matrix = InitMatrix(row, column);
	int index = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			result_matrix[i][j] = vector[index++];
		}
	}
	return result_matrix;
}


double* MatrixMultyply(double** partMatrixA, int rowA, int columnA, double** matrixB, int rowB, int columnB) {
	double** result_multiplication = InitMatrix(rowA, columnB);
	for (int i = 0; i < rowA; i++) {
		result_multiplication[i] = MultiplyRowsByColumn(partMatrixA[i], matrixB, columnA, columnB);
	}
	return fromMatrixToVector(result_multiplication, rowA, columnB);
}


double* MultiplyRowsByColumn(double* vectorA, double** matrixB, int vector_column, int matrix_column) {
	double* result_vector = new double[vector_column] {0};
	for (int i = 0; i < matrix_column; i++) {
		for (int t = 0; t < vector_column; t++) {
			result_vector[i] += vectorA[t] * matrixB[t][i];
		}
	}
	return result_vector;
}