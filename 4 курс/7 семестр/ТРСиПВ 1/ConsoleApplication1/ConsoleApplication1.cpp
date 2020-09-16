#include <iostream>
#include <fstream>
#include <vector>
#include "mpi.h"

using namespace std;

vector<vector<int>> readMatrixFromFile(string path, int* row, int* column);
vector<vector<int>> getSubMatrix(vector<vector<int>>, int, int);
void printMatrix(vector<vector<int>>);
int* matrixToVector(vector<vector<int>>);
int getMinor(int v[9]);

int main(int argc, char* argv[])
{
	MPI_Status status;
	int rank, size = 0;
	int minorSize;
	vector< vector<int> > matrix, minorMatrix;
	int* minorVector;
	int row, column;
	int determinant = 0;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	matrix = readMatrixFromFile("matrix.txt", &row, &column);
	minorSize = (matrix.size() - 1) * (matrix[0].size() - 1);

	if (rank == 0) {
		cout << "-------------------------------" << endl;
		cout << "Matrix:" << endl;
		printMatrix(matrix);

		for (int j = 0; j < column; j++) {
			minorVector = matrixToVector(getSubMatrix(matrix, 0, j));
			MPI_Send(minorVector, minorSize, MPI_INT, (j + 1), 0, MPI_COMM_WORLD);
		}

		int result;
		for (int j = 1; j < size; j++) {
			MPI_Recv(&result, 1, MPI_INT, j, 0, MPI_COMM_WORLD, &status);
			determinant += result;
		}
	}
	else {
		int* vector = new int[minorSize];
		MPI_Recv(vector, minorSize, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		int answer = matrix[0][rank - 1] * pow((-1), (1 + rank)) * getMinor(vector);
		MPI_Send(&answer, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
	}

	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();

	if (rank == 0) {
		cout << "Determinant: " << determinant << endl;
		cout << "-------------------------------" << endl;
	}

	return 0;
}

void printMatrix(vector<vector<int>> matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<int>> getSubMatrix(vector<vector<int>> matrix, int rowErasePosition, int columnErasePosition) {
	matrix.erase(matrix.begin() + rowErasePosition);

	for (int i = 0; i < matrix.size(); i++) {
		matrix[i].erase(matrix[i].begin() + columnErasePosition);
	}

	return matrix;
}


int getMinor(int v[9]) {
	int temp = v[0] * v[4] * v[8] + v[1] * v[5] * v[6] + v[2] * v[3] * v[7] - v[0] * v[5] * v[7] - v[1] * v[3] * v[8] - v[2] * v[4] * v[6];
	return temp;
}


int* matrixToVector(vector<vector<int>> matrix) {
	int row = matrix.size(), column = matrix[0].size();
	int* result = new int[row * column];

	int t = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			result[t++] = matrix[i][j];
		}
	}

	return result;
}

vector<vector<int>> readMatrixFromFile(string path, int* row, int* column) {
	ifstream in(path);

	in >> *row >> *column;

	vector<vector <int> > matrix(*row);
	for (int i = 0; i < *row; i++) {
		matrix[i].resize(*column);
	}

	for (int i = 0; i < *row; i++) {
		for (int j = 0; j < *column; j++) {
			in >> matrix[i][j];
		}
	}

	in.close();

	return matrix;
}
