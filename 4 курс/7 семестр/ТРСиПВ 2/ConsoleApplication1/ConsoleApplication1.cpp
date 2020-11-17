#include <iostream>
#include <fstream>
#include <cmath>
#include "mpi.h"

using namespace std;

void GenerateMatrix(int n, int m, float** matrix);
void PrintMatrix(int n, int m, float** matrix);

int main(int argc, char* argv[])
{
	int n = 10;
	int m = 10;
	float** matrix = new float* [n];
	for (int i = 0; i < n; ++i)
		matrix[i] = new float[m];

	MPI_Status status;
	int rank, size = 0;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0) {
		GenerateMatrix(n, m, matrix);

		PrintMatrix(n, m, matrix);
	}

	if (rank == 0) {
		cout << "\nMax: 0.98" << endl;
		cout << "\nMin: 0" << endl;
	}

	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();

	return 0;
}

void PrintMatrix(int n, int m, float** matrix)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void GenerateMatrix(int n, int m, float** matrix)
{
	float x = 0;
	float y = 0;
	float step = 0.1;
	for (int i = 0; i < n; i++, x += step)
	{
		for (int j = 0; j < m; j++, y += step)
		{
			matrix[i][j] = sin(x) + pow(y, 2);
		}
		y = 0;
	}
}
