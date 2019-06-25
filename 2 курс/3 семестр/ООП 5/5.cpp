#include <iostream>
#include<cmath>
using namespace std;
 
class Coord 
{
int x, y, delta;
public:
	Coord (int _x, int _y, int _delta)
	{
		x=_x; y=_y; delta=_delta;
	}
	
	Coord & operator ++() 
	{
		x+=delta;
		y+=delta;
		return *this;
	}
	
	friend Coord & operator !(Coord &ob1);
	
	Coord operator + (const Coord &ob2)
	{
		x=x+ob2.x;
		y=y+ob2.y;
		return *this;
	}
	
	friend bool operator >=(const Coord &ob1, const Coord &ob2);
	
	void Vivod ()
	{
		cout<<"Координата x: "<<x<<endl;
		cout<<"Координата y: "<<y<<endl;
	}
	
	friend ostream & operator << (ostream& os, const Coord & ob);  
	friend istream & operator >> (istream& is, Coord &ob);
	
};

Coord & operator !(Coord &ob1)
{
	if (!ob1.x && !ob1.y) cout<<"Координаты x1 и y1 равны 0!"<<endl;
	else cout<<"Координаты x1 и y1 не равны 0!"<<endl;
	return ob1;
}

bool operator >=(const Coord &ob1, const Coord &ob2)
{
	if (sqrt(pow(ob1.x, 2)+pow(ob1.y, 2)/2)>=sqrt(pow(ob2.x, 2)+pow(ob2.y, 2)/2)) return true;
	return false;
}

ostream & operator << (ostream& os, const Coord &ob)  
{  
    os << ob.x << '|' << ob.y << '|' << ob.delta<<endl; 
    return os;  
}  

istream & operator >> (istream& is, Coord &ob)
{
	is >> ob.x >> ob.y >> ob.delta;
	return is;
}

int main ()
{
	setlocale(0, "rus");
	
	Coord ob1(0,0,0);
	Coord ob2(0,0,0);
	cout<<"Введите координаты 1 объекта: ";
	cin>>ob1;
	cout<<"Введите координаты 2 объекта: ";
	cin>>ob2;
	cout<<"Координаты 1 объекта: "<<ob1;
	cout<<"Координаты 2 объекта: "<<ob2;
	cout<<"---------------------"<<endl;
	
	cout<<"Оператор !:"<<endl;
	!ob1;
	cout<<"---------------------"<<endl;
	
	cout<<"Оператор ++:"<<endl;
	++ob1;
	ob1.Vivod();
	cout<<"---------------------"<<endl;
	
	cout<<"Оператор >=:"<<endl;
	if (ob1>=ob2) cout<<"> или ="<<endl;
	else cout<<"<"<<endl;
	cout<<"---------------------"<<endl;
	
	cout<<"Оператор +:"<<endl;
	ob2=ob2+ob1;
	ob2.Vivod();
	
	return 0;
}
