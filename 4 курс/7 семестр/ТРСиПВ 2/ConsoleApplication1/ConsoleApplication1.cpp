#include <iostream>
#include <iomanip>
#include "mpi.h"

using namespace std;

const int N = 8;
const int M = 5;
const int K = 3;

int main(int argc, char** argv)
{
	int rank, processes;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &processes);
	int masterProcess = 0;

	int A[N][M];
	int B[M][K];
	int C[N][K];
	int blockA[2][M];
	int blockC[2][K];

	if (rank == masterProcess)
	{
		int dataA[N][M] = {
			{1, 2, 3, 4, 5},
			{6, 7, 8, 9, 10},
			{11, 12, 13, 14, 15},
			{16, 17, 18, 19, 20},
			{21, 22, 23, 24, 25},
			{26, 27, 28, 29, 30},
			{31, 32, 33, 34, 35},
			{36, 37, 38, 39, 40},
		};

		int dataB[M][K] = {
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9},
			{10, 11, 12},
			{13, 14, 15},
		};

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < K; j++) {
				B[i][j] = dataB[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				A[i][j] = dataA[i][j];
			}
		}
	}

	// Широковещательная рассылка
	MPI_Bcast(B, M * K, MPI_INT, masterProcess, MPI_COMM_WORLD);
	MPI_Scatter(A, 10, MPI_INT, blockA, 10, MPI_INT, masterProcess, MPI_COMM_WORLD);

	// Вычисления
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < K; j++) {
			blockC[i][j] = 0;
			for (int g = 0; g < M; g++) {
				blockC[i][j] += blockA[i][g] * B[g][j];
			}
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < K; j++) {
			cout << setw(6) << blockC[i][j] << " ---" << rank << "---";
		}
		cout << endl;
	}

	// Взаимная синхронизация
	MPI_Barrier(MPI_COMM_WORLD);

	// Совместная передача данных процессу-мастеру
	MPI_Gather(blockC, 6, MPI_INT, C, 6, MPI_INT, masterProcess, MPI_COMM_WORLD);

	if (rank == masterProcess) {
		cout << endl << endl << "Result matrix: " << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < K; j++) {
				cout << setw(6) << C[i][j] << " ";
			}
			cout << endl;
		}
	}

	MPI_Finalize();

	return 0;
}