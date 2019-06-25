#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std; 

class Aqua
{
public:
	int obm;
	
	Aqua()
	{
		cout<<"Введите Объём воды: ";
		cin>>obm;
	}
	
	
	void Vivod()
	{
		cout<<"Данные класса Вода:"<<endl;
		cout<<"Объем воды: "<<obm<<endl;
	}
};


class Substance
{	
public:
	int ves;
	char *name, *type;
	
	Substance()
	{
		name=new char [10];
		type=new char [10];
		cout<<"Введите Вес вещества: ";
		cin>>ves;
		cout<<"Введите Имя вещества: ";
		cin>>name;
		cout<<"Введите Тип вещества: ";
		cin>>type;
	}
	
	~Substance()
	{
		delete [] name;
		delete [] type;
	}
	
	void Vivod()
	{
		cout<<"Данные класса Вещество:"<<endl;
		cout<<"Вес вещества: "<<ves<<endl;
		cout<<"Имя вещества: "<<name<<endl;
		cout<<"Тип вещества: "<<type<<endl;
	}
};


class Rastvor : public Aqua, public Substance
{
public:
	int plus, minus;
	
	void Ink()
	{
		cout<<"Введите на сколько увеличить объём: "<<endl;
		cin>>plus;
		obm+=plus;
		cout<<"Введите на сколько уменьшить вес: "<<endl;
		cin>>minus;
		ves-=minus;
		cout<<"Выполнено!"<<endl;
	}
	
	void Vivod()
	{
		cout<<"Объём воды: " <<obm<<endl;
		cout<<"Вес вещества: "<<ves<<endl;
		cout<<"Имя вещества: "<<name<<endl;
		cout<<"Тип вещества: "<<type<<endl;
		
	}
};


int main ()
{
	setlocale(0, "RUS");
	
	int key;
	
	cout<<"Создание объектов базового класса:"<<endl;
	Rastvor ob3;
	
	while (1)
	{
		system("cls");
		cout << "1 - Вызов объектом производного класса методов базовых классов(Просмотр)" << endl;
		cout << "2 - Просмотр объекта производного класса" << endl;
		cout << "3 - Вызов уникального метода производного класса" << endl;
		cout << "4 - Выход" << endl;
		key=getch(); 
		switch (key)
		{
			case'1':
			{
				ob3.Aqua::Vivod();
				cout<<"-----------------------"<<endl;
				ob3.Substance::Vivod();
				system("pause");
				break;
			} 
			case '2':
			{   
				cout<<"Данные класса Раствор:"<<endl;
				ob3.Vivod();
				system("pause");
				break;
			}
			case '3':
			{
				ob3.Ink();
				system("pause");
				break;
			}
			case '4': return 0;
			default: cout << "Введите число от 1 до 4:" << endl;
		}
	}
}
