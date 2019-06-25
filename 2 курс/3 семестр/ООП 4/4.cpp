#include <iostream>
using namespace std;
 
class matrix;
class vector 
{
int size, *vec;
public:
	vector(int _size)
	{
		vec = new int [size=_size];
	}
	
	virtual ~vector()
	{
		delete [] vec;
	}
	
	friend void min(vector ob1, matrix ob2);
	
	void vvod_vec()
	{
		for(int i=0; i<size; i++)
		{                                              
			cout <<"Введите значения вектора ["<<i+1<<"]: ";
			cin >> vec[i];
		}
	}
};
 
class matrix
{
int str, st, **mtx;
public:
	matrix (int _str, int _st)
	{
		mtx = new int *[str=_str];
		for(int i = 0; i<str; i++) mtx[i] = new int [st=_st];   
	}
	
	~matrix()
	{
		for(int i = 0; i<str; i++) delete[] mtx[i];
		delete []mtx;
	}
	
	friend void min(vector ob1, matrix ob2);
	
	void vvod_mtx()
	{
		for(int i=0; i<str; i++)                                 
		for(int j=0; j<st; j++)
		{		
			cout << "Введите значения матрицы ["<<i+1<<"]["<<j+1<<"]: ";
			cin >> mtx[i][j];
		}
	}
};
 
void min(vector ob1, matrix ob2)
{
	int min1, min2;
	
	min1=ob1.vec[0];
	for(int i=0; i<ob1.size; i++) 
	{
		if(min1 > ob1.vec[i]) min1 = ob1.vec[i]; 
	}
	
	min2=ob2.mtx[0][0];
	for(int j=0; j<ob2.str; j++) 
	for(int k=0; k<ob2.st; k++) 
	{
		if(min2 > ob2.mtx[j][k]) min2 = ob2.mtx[j][k]; 
	}
	
	cout<<"Минимальный элемент вектора: "<<min1<<endl;
	cout<<"Минимальный элемент матрицы: "<<min2<<endl;
	if (min1==min2) cout<<"Равны!"<<endl;
	else cout<<"Не равны!"<<endl;
}
 
int main()
{ 
	setlocale(0, "Rus");
	int s, s1, s2;
	
	cout<<"Введите размер вектора: ";
	cin>>s;
	cout<<"Введите размер матрицы: ";
	cin>>s1>>s2;
	
	vector ob1(s);
	matrix ob2(s1, s2);
	
	ob1.vvod_vec();
	ob2.vvod_mtx();
	
	min(ob1,ob2);
	return 0;
}
