#include <conio.h>
#include <time.h>
#include <ctime>
#include <windows.h>
#include <iostream>
using namespace std;

const int N = 10000;

struct student {
	char fio[10];
	int faculty;
	int kurs;
};

// сортировка модифицированным пузырьком
void modBubble(student *a, int n)
{
	int i=n,t;
	int f;
	do {
		f=0;
		for (int j=0; j<i-1; j++)
		if (a[j].kurs < a[j+1].kurs)
		{
			swap(a[j], a[j + 1]);
			f=1;
		}
		i--;
	} while (f && i>1);
}

// сортировка выбором
void selectSort(student *a, int n) 
{
	int i, j, imax;
	for(i = n; i > 1; i--) 
	{
		imax = 0;
		for(j = 1; j <= i; j++)
		{
			if(a[j].kurs < a[imax].kurs)
				imax = j;
			swap(a[i], a[imax]);
		}
	}
}

// быстрая сортировка
void quickSort(student *a, int n) 
{
	int i = 0, j = n;
	student p;
	p.kurs = a[n / 2].kurs;
	do 
	{
		while (a[i].kurs > p.kurs) i++;
		while (a[j].kurs < p.kurs) j--;
		if (i <= j) 
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) quickSort(a, j);
	if (n > i) quickSort(a + i, n - i);
}

int main()
{
	FILE *stream;
	stream = fopen("Result.txt", "w+");
	setlocale(0, "rus");
	student a[N];
	int n = N;
	int key;
	for (int i = 0; i < n; i++)
		a[i].kurs = rand()%100;
	cout << "Выбор сортировки: " << endl;
	cout << "1 - Пузырьком" << endl;
	cout << "2 - Выбором" << endl;
	cout << "3 - Быстрая" << endl;
	cout << "Ваш выбор: ";
	cin >> key;
	double start_time, end_time;
	switch (key)
	{
		case 1:
			start_time = clock();
			modBubble(a, N);
			end_time = clock();
			break;
		case 2:
			start_time = clock();
			selectSort(a, N);
			end_time = clock();
			break;
		case 3:
			start_time = clock();
			quickSort(a, N);
			end_time = clock();
			break;
	}
	double time = end_time - start_time;
	cout << "Результаты сортировки занесены в файл Result.txt" << endl;
	for (int i = 0; i < n; i++)
		fprintf(stream, "%i ", a[i].kurs);
	cout << "Время работы программы (MS) = " << time/(double)CLOCKS_PER_SEC << endl;
	fclose(stream);
	return 0;
}
