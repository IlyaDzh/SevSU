#include <iostream>
using namespace std;

int main ()
{	
	setlocale(0, "rus");
	
	int k;
	cout<<"¬ведите размер числа: "; cin>>k;
	
	char *str1=new char[k];
	char *str2=new char[k];
	char *str3=new char[k];
	
	cout<<"¬ведите первое число: "; cin>>str1;
	cout<<"¬ведите второе число: "; cin>>str2;
	
	cout<<"–езультат:            ";
	for (int i=0; i<k; i++) 
	{
		str3[i]=str1[i]|str2[i];
		cout<<str3[i];
	}
}
