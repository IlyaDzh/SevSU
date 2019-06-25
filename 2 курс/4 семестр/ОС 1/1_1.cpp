#include <iostream>
using namespace std;
int main()
{
	setlocale(0,"rus");
	int n;
	cout<<"¬ведите кол-во элементов: ";
	cin>>n;
	int a[n];
	for (int i=0; i<n; i++)
	{
		cout<<"¬ведите ["<<i+1<<"] элемент массива: ";
		cin>>a[i];	
	}
	cout<<"»сходный:"<<endl;
	for (int i=0; i<n; i++)
		cout<<a[i]<<" ";	
	cout<<endl<<"–езультат:"<<endl;
	for (int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if (a[i]>a[j])
			{
				int buf = a[i];
				a[i]=a[j];
				a[j]=buf;
			}
		}
		cout<<a[i]<<" ";
	}
}
