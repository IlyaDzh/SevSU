#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include <iostream>
using namespace std;

int vector[400];
int i;

void create_array(int Nmax) 
{
	FILE *stream;
	stream = fopen("Example_TA2.TXT", "w+");
	srand(time(0));
	for (i = 0; i<Nmax; i++) 
	{
		vector[i] = rand() % 951;
		fprintf(stream, "%d ", vector[i]);
	}
	fclose(stream);
}

float harmonic(int N)
{ 
	float h = 0; 
	h = log(N) + 0.57; 
	return h; 
} 

int main() 
{
	setlocale(0, "rus");
	int i, N, min, cnt;
	double result;
	cout << "Введите кол-во чисел: "; cin >> N;
	result = harmonic(N);
	cout << "Гармоническое число: "<<result<<endl;
	create_array(N);
	min = vector[0];
	cnt = 1;
	for (i = 1; i<N; i++) {
		if (vector[i]<min) { min = vector[i]; cnt++; }
	}
	printf("%s%d%s%d\n", "Минимальный: ", min, " Номер операции: ", --cnt);
}
