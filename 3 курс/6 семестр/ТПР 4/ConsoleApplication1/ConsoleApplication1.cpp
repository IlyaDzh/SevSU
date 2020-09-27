#include <iostream>

using namespace std;

const int n_f = 2;
const int n_x = 10;
int in_array[n_x][n_f] = {
		{3, 2},
		{5, 6},
		{5, 4},
		{8, 4},
		{6, 2},
		{3, 8},
		{6, 4},
		{2, 5},
		{9, 2},
		{3, 9}
};
int** out_array, ** array_f1, ** array_f2;
int delta[n_f] = { 0, 0 };
int index[n_f] = { 1, 1 };
int result[n_f];

void find_dominated(int n_x, int n_f, int* matrix);
int** fill_out_array(int n_x, int n_f, int x, int* matrix);
unsigned int count_not_dominated(int n_x, int* matrix);
void sort(int ind, int n_x, int n_f, int** matrix);

int main()
{
	setlocale(LC_ALL, "Russian");

	find_dominated(n_x, n_f, &in_array[0][0]);
	unsigned int x = count_not_dominated(n_x, &in_array[0][0]);
	out_array = fill_out_array(n_x, n_f, x, &in_array[0][0]);

	// вспомогательные массивы для метода уступок
	array_f1 = new int* [x];
	for (unsigned int i = 0; i < x; i++)
		array_f1[i] = new int[n_f];
	array_f2 = new int* [x];
	for (unsigned int i = 0; i < x; i++)
		array_f2[i] = new int[n_f];

	// заполним их
	for (unsigned int i = 0; i < x; i++)
		for (int j = 0; j < n_f; j++)
			array_f1[i][j] = array_f2[i][j] = out_array[i][j];

	// отсортируем  их
	sort(0, x, n_f, array_f1);
	sort(1, x, n_f, array_f2);

	// выведем все наши матрицы
	cout << "Парето - граница:" << endl;
	for (unsigned int i = 0; i < x; i++) {
		for (int j = 0; j < n_f; j++)
			cout << out_array[i][j] << " ";
		cout << endl;
	}
	cout << "f1max:" << endl;
	for (unsigned int i = 0; i < x; i++) {
		for (int j = 0; j < n_f; j++)
			cout << array_f1[i][j] << " ";
		cout << endl;
	}
	cout << "f2max:" << endl;
	for (unsigned int i = 0; i < x; i++) {
		for (int j = 0; j < n_f; j++)
			cout << array_f2[i][j] << " ";
		cout << endl;
	}

	//  метод уступок
	while (true) {
		if (array_f1[index[0]][0] == array_f2[index[1]][0] and array_f1[index[0]][1] == array_f2[index[1]][1]) {
			result[0] = array_f1[index[0]][0];
			result[1] = array_f1[index[0]][1];
			break;
		}
		if (array_f1[index[0] - 1][0] == array_f2[index[1]][0] and array_f1[index[0]][1] == array_f2[index[1] - 1][1]) {
			delta[0] += (array_f1[index[0] - 1][0] - array_f1[index[0]][0]);
			delta[1] += (array_f2[index[1] - 1][1] - array_f2[index[1]][1]);
			if (delta[0] > delta[1]) {
				result[0] = array_f1[index[0] - 1][0];
				result[1] = array_f1[index[0] - 1][1];
				break;
			}
			if (delta[0] < delta[1]) {
				result[0] = array_f2[index[0] - 1][0];
				result[1] = array_f2[index[0] - 1][1];
				break;
			}
			result[0] = array_f1[index[0] - 1][0];
			result[1] = array_f1[index[0] - 1][1];
			break;
		}
		delta[0] += (array_f1[index[0] - 1][0] - array_f1[index[0]][0]);
		delta[1] += (array_f2[index[1] - 1][1] - array_f2[index[1]][1]);
		if (delta[0] == delta[1]) {
			index[0]++, index[1]++;
			continue;
		}
		if (delta[0] > delta[1]) {
			index[1]++;
			continue;
		}
		if (delta[0] < delta[1]) {
			index[0]++;
			continue;
		}
	}
	cout << "Наиболее эффективное решение:" << endl;
	cout << "f1 = " << result[0] << ", f2 = " << result[1] << endl;

	// освобождение памяти
	for (unsigned int i = 0; i < x; i++) {
		delete[]out_array[i];
		delete[]array_f1[i];
		delete[]array_f2[i];
	}

	return 0;
}

void find_dominated(int n_x, int n_f, int* matrix)
{
	unsigned int i_want_to_eat_smt_delicious;
	unsigned int second_one_wins;
	for (int now = 0; now < n_x; now++)
		for (int i = 0; i < (n_x); i++) {
			i_want_to_eat_smt_delicious = second_one_wins = 0;
			for (int j = 0; j < n_f; j++) {
				if ((*(matrix + now * n_f + j)) > (*(matrix + i * n_f + j)))
					i_want_to_eat_smt_delicious++;
				else {
					if ((*(matrix + now * n_f + j)) == (*(matrix + (i)*n_f + j))) {
						i_want_to_eat_smt_delicious++;
						second_one_wins++;
					}
					else
						second_one_wins++;
				}
			}
			if (i_want_to_eat_smt_delicious == second_one_wins)
				continue;
			else {
				if (i_want_to_eat_smt_delicious > second_one_wins) {
					for (int k = 0; k < n_f; k++)
						(*(matrix + (i)*n_f + k)) = -100;
				}
				else
					for (int k = 0; k < n_f; k++) {
						(*(matrix + now * n_f + k)) = -100;
						break;
					}
			}
		}
}

int** fill_out_array(int n_x, int n_f, int x, int* matrix)
{
	int** array = new int* [x];
	for (int i = 0; i < x; i++)
		array[i] = new int[n_f];
	int count = 0;
	for (int i = 0; i < n_x; i++) {
		if ((*(matrix + i * n_f)) != -100) {
			for (int j = 0; j < n_f; j++)
				array[count][j] = *(matrix + i * n_f + j);
			count++;
		}
	}
	return array;
}

unsigned int count_not_dominated(int n_x, int* matrix)
{
	unsigned int count = 0;
	for (int i = 0; i < n_x; i++)
		if ((*(matrix + i * n_f)) != -100)
			count++;
	return count;
}

void sort(int ind, int n_x, int n_f, int** matrix)
{
	for (int i = n_x - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (matrix[j][ind] < matrix[j + 1][ind])
			{
				int tmp[2];
				tmp[0] = matrix[j][0];
				tmp[1] = matrix[j][1];
				matrix[j][0] = matrix[j + 1][0];
				matrix[j][1] = matrix[j + 1][1];
				matrix[j + 1][0] = tmp[0];
				matrix[j + 1][1] = tmp[1];
			}
		}
	}
}
