#include <iostream>

using namespace std;

void OddEvenSort(int* vector, int size);
void ShowVector(int vector[], int size);

int main()
{
	const int size = 15;
	int A[size] = { 41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61 };

	ShowVector(A, size);
	OddEvenSort(A, size);
	ShowVector(A, size);
}

void OddEvenSort(int* vector, int size)
{
	for (int i = 0; i < size; i++) 
	{
		if (i % 2 == 0) 
		{
			for (int j = 0; j < size; j += 2) 
			{
				if (j < size - 1) 
				{
					if (vector[j] > vector[j + 1])
					{
						int tmp = vector[j];
						vector[j] = vector[j + 1];
						vector[j + 1] = tmp;
					}
				}
			}
		}
		else 
		{
			for (int j = 1; j < size; j += 2) 
			{
				if (j < size - 1) 
				{
					if (vector[j] > vector[j + 1])
					{
						int tmp = vector[j];
						vector[j] = vector[j + 1];
						vector[j + 1] = tmp;
					}
				}
			}
		}
	}
}

void ShowVector(int vector[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << vector[i] << " ";
	}
	cout << endl;
}