#include <iostream>
#include <conio.h>
using namespace std;

struct drob 
{
	float ch, zn;
};

float summa (drob d1, drob d2)
{
	float s = (d1.ch*d2.zn+d2.ch*d1.zn)/(d1.zn*d2.zn);
	return s;
}
int main()
{
	float s=0;
	struct drob d1;
	struct drob d2;
	cout<<"Vvedite ch. 1 drobi:"; cin>>d1.ch;
	cout<<"Vvedite zn. 1 drobi:"; cin>>d1.zn;
	cout<<"Vvedite ch. 2 drobi:"; cin>>d2.ch;
	cout<<"Vvedite zn. 2 drobi:"; cin>>d2.zn;
	s=summa(d1, d2);
	cout<<"Result:"<<s;
	return 0;
}
