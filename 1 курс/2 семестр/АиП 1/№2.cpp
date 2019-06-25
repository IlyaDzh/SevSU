#include <conio.h>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
main()
{	setlocale(0,"RUS");
	float a, b, x, z, xn, xk, dx;
	cout<<"Введите параметр a:  ", cin>>a;
	cout<<"Введите параметр b:  ", cin>>a;
	cout<<"Введите xn: ", cin>>xn;
	cout<<"Введите xk: ", cin>>xk;
	cout<<"Введите шаг dx: ", cin>>dx;
	cout<<"Таблица значений функции z=f(x)"<<endl
	<<"  --------------------------"<<endl
	<<"  |     x     |  z = f(x)  |"<<endl
	<<"  |-----------|------------|"<<endl;
	cout.precision(3), cout.setf(ios::showpoint);
	cout.setf(ios::left,ios::adjustfield);
	cout.setf(ios::fixed,ios::floatfield);
	for(x=xn;x<=xk;x+=dx)
	{	cout<<"  |  "<<setw(9)<<x<<'|';
		(x<=a)? z=log10(pow(pow(x,2), 1/3)+sqrt(x)+sin(x)+cos(x)) : (a<x<b)? z=pow((pow(tan(x),2)+1.3*exp(cosh(x)+tanh(x))),pow(x,2)) : z=abs(sin(x)-0.11)*acos(x)+pow(x,asin(x));
    	cout<<"  "<<setw(10);
    	cout<<z;
		cout<<'|'<<endl;
	}
	cout<<"  --------------------------"<<endl;
	cout<<"Нажмите любую клавишу...";
	getch();
	return 0;
}
