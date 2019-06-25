#include <iostream>
#include <fstream> 
#include <iomanip>
using namespace std;

class vector 
{
public:
	int size, v;
	float *vec;
	vector(int _size)
	{
		vec = new float [size=_size];
	}
	~vector()
	{
		delete [] vec;
	}
	void vvod_vec()
	{
		for(int i=0; i<size; i++)
		{                                              
			cout <<"¬ведите значени€ вектора ["<<i+1<<"]: ";
			try 
			{
				if(!(cin >> vec[i])) throw 1;
			}
			catch(int)
			{
				
				cin.clear();
				while(cin.get()!='\n') continue;
				cout<<"   ¬ведите число: "; cin>>vec[i];
				
			}
		}
	}
	void vivod()
	{
		for(int i=0; i<size; i++)
		{                                              
			cout <<"«начени€ вектора ["<<i+1<<"]: "<<vec[i]<<endl;
		}
	}
};

int main()
{
	setlocale(0, "rus");

    double a, b;
    ofstream fout("1.txt"); 
    cout<<"1 задание:"<<endl;
    cout<<"¬ведите a: "; cin>>a;
    cout<<"¬ведите b: "; cin>>b;
    double x = (-b)/a;
	if (a==0)
	{
		if (b==0) fout<<"X - любое число";
		else fout<<setfill('%')<<setw(12)<<"–ешений нет";
	}
	else 
	{
		fout.fill ('%'); fout.width (12);
    	fout<<"x="<<setprecision(4)<<x<<endl;
	}
	cout<<"–езультат в файле!"<<endl;
	fout.close(); 
	
	
	cout<<"\n2 задание:"<<endl;
	vector ob(4);
	ob.vvod_vec();
	ob.vivod();
    return 0;
}
