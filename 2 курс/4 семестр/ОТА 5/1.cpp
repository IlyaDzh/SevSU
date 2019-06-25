#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

const int n = 9; // количество вершин
const int MAX_INT = 1000000;

void solve(int g[n][n], int d[n], int s) 
{
	int i, j, // i-я итерация, j - для поиска минимальной
	v, // минимальная вершина
	to, // ребро из вершины v в to
	len; // длины len
	bool used[n] = {false}; // массив для пометок вершин
	d[s] = 0;
	for (i = 0; i < n; i++) 
	{
		v = -1;
		for (j = 0; j < n; j++) // поиск вершины с минимальным d[j]
			if (!used[j] && (v == -1 || d[j] < d[v]))
				v = j;
		used[v] = true; // пометка вершины
		for (to = 0; to < n; to++) 
		{
			if (g[v][to]) 
			{
				len = g[v][to];
				if (d[v] + len < d[to]) 
				{
					d[to] = d[v] + len;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << d[i] << " ";
}

int main()
{
	double start_time, end_time;
	int s = 0; // стартовая вершина
	setlocale(LC_ALL, "Russian");
	int g[n][n] = {
		0, 1, 10, 0, 0, 0, 0, 0, 0,
		0, 0, 3, 3, 0, 0, 7, 0, 0,
		0, 0, 0, 0, 2, 7, 0, 5, 0,
		0, 0, 2, 0, 4, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 3, 0, 0,
		0, 0, 0, 0, 2, 0, 0, 0, 0,
		0, 0, 3, 0, 0, 5, 0, 0, 7,
		0, 0, 0, 0, 0, 0, 0, 0, 7,
		0, 0, 0, 0, 0, 0, 0, 0, 0,
	}; // матрица смежности
	int d[n]; // массив ответов
	for (int i = 0; i < n; i++)
		d[i] = MAX_INT;
	start_time = clock();
	cout << "Кратчайшие расстояния:" << endl;
	solve(g, d, s);
	end_time = clock();
	double time = end_time - start_time;
	cout << "\nВремя работы программы (MS) = " << time/(double)CLOCKS_PER_SEC << endl;
	return 0;
}
