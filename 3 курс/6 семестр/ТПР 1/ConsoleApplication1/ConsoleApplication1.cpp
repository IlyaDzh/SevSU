#include <iostream>
#include <fstream>

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
	int resultMas[n];
	int count = 0;
	int sum;
	int floor = 1;

	while (count < n) {
		std::cout << "Ярус " << floor++ << ": ";
		for (int j = 0; j < n; j++) {
			sum = 0;
			for (int i = 0; i < n; i++)
				sum += matr[i][j];
			if (sum == 0) {
				std::cout << "x" << j + 1 << " ";
				MaxR[count] = j;
				resultMas[count] = j+1;
				count++;
			}
		}

		for (int q = count - 1; q >= 0; q--)
			for (int j = 0; j < n; j++)
				matr[MaxR[q]][j] = 0;
		for (int q = count - 1; q >= 0; q--)
			for (int i = 0; i < n; i++)
				matr[i][MaxR[q]] = 1;

		for (int i = 0; i < n; i++) {
			std::cout << std::endl;
			for (int j = 0; j < n; j++)
				std::cout << matr[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "Множество решений: ";
	for (int i = 0; i < n; i++)
		std::cout << "x" << resultMas[i] << " ";
}