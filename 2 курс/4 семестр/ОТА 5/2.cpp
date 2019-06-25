#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

const int INF = 1000000000; // бесконечность
const int n = 9; // количество вершин
bool used[n] = { 0 }; // массив для пометок
int top[n] = { 0 }; // топологический список
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
int l; // l-я вершина для добавления
int s = 0; // стартовая вершина
int f; // конечная вершина
int d[n] = { 0 }; // массив ответов

int dfs(int v) 
{
	if (used[v])
		return 0;
	used[v] = true;
	for (int to = 0; to < n; to++)
		if (g[v][to])
			dfs(to);
	top[l++] = v; // добавление вершины v в отсортированный список
}

int topSort() 
{
	l = 0; // номер добавляемой вершины в отсортированный список
	for (int i = 0; i < n; i++)
		dfs(i); // запустить пробежку из всех вершин
	reverse(top, top + l); // развернуть массив
	return 0;
}

int solve() 
{
	int i, j;
	for (i = 0; i < n; i++)
		d[i] = INF;
	d[s] = 0;
	for (i = 1; i < n; i++)
	for (j = 0; j < i; j++)
		if (g[top[j]][top[i]])
			d[top[i]] = min(d[top[i]], d[top[j]] + g[top[j]][top[i]]);
	for (int i = 0; i < n; i++)
		cout << d[i] << " ";
	return 0;
} 

int main() 
{
	setlocale(LC_ALL, "Russian");
	double start_time, end_time;
	start_time = clock();
	cout << "Кратчайшие расстояния:" << endl;
	topSort();
	solve();
	end_time = clock();
	double time = end_time - start_time;
	cout << "\nВремя работы программы (MS): " << time/(double)CLOCKS_PER_SEC << endl;
}
