#include <iostream>
using namespace std;

template <typename T>
T MaxI(T *arr, int n)
{
	int maxcount=1, nn=-1;
    for (int i = 0; i < n; i++)
    {
        int count=0;
        for (int j = i; j < n; j++) if (arr[i] == arr[j]) count++;
        if (maxcount < count)
        {
            maxcount = count;
            nn = i;
        }
    }
    if (nn > -1) cout << arr[nn] << endl;
    else cout <<"Нет повторяющися эллементов";
}

int main ()
{
	setlocale(0, "rus");
	const int n=10;
	int arr1[n]{1,2,3,4,4,5,2,2,1,2};
	float arr2[n]{1.2, 2.5, 3.8, 1.2, 1.2, 2.3, 2.5, 1.2, 2, 9};
	char* arr3="fghgfffhfg";

	cout<<"Массив int типа: ";
	for (int i=0; i<n; i++) 
	{
		cout<<arr1[i]<<" ";
	}
	cout<<"\nМассив float типа: ";
	for (int i=0; i<n; i++) 
	{
		cout<<arr2[i]<<" ";
	}
	cout<<"\nМассив char типа: ";
	for (int i=0; i<n; i++) 
	{
		cout<<arr3[i]<<" ";
	}
	cout<<endl;
	
	MaxI(arr1, n);
	MaxI(arr2, n);
	MaxI(arr3, n);
	
	return 0;
}
