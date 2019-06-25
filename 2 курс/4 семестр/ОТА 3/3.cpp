#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

void create_array(int N, int vector[])
{
	srand(time(NULL));
	for(int i = 0; i < N; i++)
		vector[i] = rand () % 91;
}

void tasksum(int N, int vector[])
{
	int counter = 0;
	int V = 25; 
	int Cnt[N]; 
	int i = 0; 
	counter += 3;
	do
	{
		Cnt[i] = 0;
		i += 1; 
	}
	while (i < N); 
	counter += 5*N;
	do
	{
		int Sum = 0; 
		for(int i = 0; i < N; i++) 
			Sum = Sum + vector[i]*Cnt[N-i]; 
		counter += 1+10*N;
		if (Sum == V) 
		{
			counter++;
			for(int i = N; i >= 1; i--)
				cout << Cnt[i] << " ";
			counter += 1+4*N;
			cout <<endl<< "Число операций: "<<counter<<endl;
			return;
		}
		int j = N;
		while (Cnt[j] == 1)
		{
			Cnt[j] = 0;
			j = j-1;
		}
		Cnt[j] = 1;
		counter += 5+6*N;
	}
	while (Cnt[0] != 1);
	for(int i = N; i >= 1; i--)
		cout << Cnt[i] << " ";
	cout <<endl<< "Число операций: "<<counter<<endl;
}

int main()
{
	setlocale(0, "rus");
	int N;
	cout << "Размер вектора: "; cin >> N;
	cout << "Макс. случайное число в векторе: 90" << endl;
	cout << "Значение суммы V: 25" << endl;
	int Hn = (8*N*pow(2,N)+16*pow(2,N)-3*N-12);
	cout<<"F^(N): "<<Hn<<endl;
	int vector[N];
	create_array(N, vector);
	
	cout<<endl;
	cout << "Рандомный вектор:" << endl;
	for(int i = 0; i < N; i++)
		cout << vector[i] <<" ";
	cout<<endl;
	tasksum(N, vector);
	system("pause");
	
	cout<<endl;
	cout << "Вручную:" << endl;
	int vector1[N];
	for(int i=0; i<N ;i++)
		cin >> vector1[i];
	tasksum(N, vector1);
	system("pause");
	
	return 0;
}
