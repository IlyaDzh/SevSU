#include <iostream>
#include <fstream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");

	const int n = 7;
	int matr[n][n] = {
		{0,1,1,0,0,0,0},
		{0,0,1,0,0,0,0},
		{0,0,0,0,0,1,1},
		{0,1,0,0,0,1,0},
		{0,1,0,1,0,1,0},
		{0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0}
	};
	int MaxR[n];
	int count = 0;
	int tempCount = 0;
	int sum;
	int floor = 1;

	while (count < n) {
		tempCount = count;
		cout << "Ярус " << floor++ << ": ";
		for (int j = 0; j < n; j++) {
			sum = 0;
			for (int i = 0; i < n; i++)
				sum += matr[i][j];
			if (sum == 0) {
				cout << "x" << j + 1 << " ";
				MaxR[count] = j;
				count++;
			}
		}

		if (tempCount == count) {
			cout << "Невозможно определить вершину-источник" << endl;
			break;
		}
		else if (count - tempCount > 1) {
			cout << "(Решения несравнимы)";
		}

		for (int q = count - 1; q >= 0; q--)
			for (int j = 0; j < n; j++)
				matr[MaxR[q]][j] = 0;
		for (int q = count - 1; q >= 0; q--)
			for (int i = 0; i < n; i++)
				matr[i][MaxR[q]] = 1;

		for (int i = 0; i < n; i++) {
			cout << endl;
			for (int j = 0; j < n; j++)
				cout << matr[i][j] << " ";
		}
		cout << endl;
	}
}