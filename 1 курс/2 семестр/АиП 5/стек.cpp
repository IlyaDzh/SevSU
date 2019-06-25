#include <fstream> 
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <time.h> 
#include <iomanip> 
#include <conio.h> 
#include <iostream> 
using namespace std; 
//----------------------------константы----------------------------------------------- 
const int d_o=20, d_n=20;
 //-----------------------структура элемента----------------------------------------- 
struct zakaz  
{ 
	int nomer;
	char otpravlenie[d_o], naznachenie[d_n];       
	float price, time_o, time_p;
	zakaz* next;
}; 
//------------------------прототипы функций----------------------------------------- 
zakaz* dob(zakaz* beg, const zakaz& z);
zakaz* add_end(zakaz *beg,const zakaz& z);
zakaz* dob_first(const zakaz& z);
zakaz* udal(zakaz* beg); 
zakaz vvod_zakaza();
int  menu();
void print(const zakaz& z);
void prosmotr(zakaz* beg);
int  read_file(char* filename, zakaz** beg, zakaz** end);
int  write_file(char* filename, zakaz* temp);
//-------------------------основная функция------------------------------ 
int main() 
{    
	setlocale(0,"RUS"); 
	zakaz *beg=0,     //указатель начала очереди         
	*end=0;    //указатель конца очереди       
 	char *filename="123.txt";          
 	read_file(filename,&beg, &end); //чтение данных из файла в очередь 
 	while (1)  
	{ 
		switch (menu())		//отобразить меню и сделать выбор     
		{ 
		case 1: if (beg)     //если очередь не пустая, 
			  		beg=dob(beg,vvod_zakaza()); 	//то добавляем элемент в конец,     
				else {  
					  beg=dob_first(vvod_zakaza());//создаем первый элемент очереди.   
					  end=beg;     //указатели начала и конца равны   
					 }      
				break;  
		case 2: end=add_end(end,vvod_zakaza());       
				break;  
		case 3: beg=udal(beg);        
				cout<<"Нажмите любую клавишу"<<endl;      
				cin.get();      
				break;  
		case 4: prosmotr(beg);  
				break;  
		case 5: write_file(filename,beg);   
				break;  
		case 6: return 0;  
		default:    
				cout<<"Вам следует ввести номер от 1 до 5"<< endl;      
				cin.get();      
				break;  
		}       
	} 
} 
//-----------------------добавление элемента----------------------------- 
zakaz* dob(zakaz *beg,const zakaz& z)
{         
	zakaz *newE=new zakaz;
	*newE=z;
	newE->next=beg;  
	beg=newE; 
	return beg; 
} 
//----------------------создание первого элемента------------------------ 
zakaz* dob_first(const zakaz& z)  
{ 
	zakaz *beg=new zakaz;   //выделение памяти под элемент  
	*beg=z;     //присвоить значения элементу  
	beg->next=0;    //ссылка на следующий эл-т нулевая  
	return beg;     //вернуть указатель на элемент 
} 
// ---------------- печать и удаление элемента--------------------------- 
zakaz* udal(zakaz *beg)  
{ 
	zakaz *temp;  
	if (!beg) { cout<<"Очередь пустая"<<endl; return 0; }  
	cout<<"=============================="<<endl;  
	print(*beg);    //печать значений головного эл-та  
	cout<<"=============================="<<endl;  
	temp=beg;     //запомнить указатель на голову  
	beg=beg->next;    //перевод beg на следующий эл-т  
	delete temp;    //удаление элемента   
	return beg;     //вернуть измененное значение beg 
} 
//-------------------ввод значений элемента------------------------------ 
zakaz vvod_zakaza()  
{   
	zakaz z;  
	cout<<"Введите станцию отправления:"<<endl;  
	cin.getline(z.otpravlenie,d_o);  
	cout<<"Введите станцию назначения:"<<endl;  
	cin.getline(z.naznachenie,d_n);  
	cout<<"Введите время отправления:"<<endl;  
	cin>>z.time_o; 
	cout<<"Введите время прибытия:"<<endl;  
	cin>>z.time_p; 
	cout<<"Введите стоимость билета:"<<endl;  
	cin>>z.price; 
	cout<<"Введите номер поезда:"<<endl;  
	cin>>z.nomer; 
	return z; 
} 
//-----------------отображение меню и  ввод пункта меню----------------------- 
int menu() 
{  
	char buf[10];  
	int item;  
	do    
	{
		system("CLS");       
		cout<<"1- Добавление элемента в стек"<<endl;    
		cout<<"2- Добавление элемента в конец"<<endl;  
		cout<<"3- Удаление элемента"<<endl;    
		cout<<"4- Просмотр стека"<<endl; 
		cout<<"5- Запись данных в файл"<<endl;     
		cout<<"6- Выход"<<endl;     
		cout<<"============================"<<endl;     
		cout<<"Введите номер пункта меню:"<<endl;     
		cin>>buf;    
		cin.get();     
		item=atoi(buf);    //преобразовать его в целое     
		if (!item) 
		{                    
			cout<<"Вам следует вводить число от 1 до 5"<<endl;                     
			cin.get();                     
		}  
	} 
	while (!item);
	return item;
} 
// -----------------------------печать заказа----------------------------- 
void print(const zakaz& z)  
{ 
	cout<<"Станция отправления: " <<z.otpravlenie <<endl;  
	cout<<"Станция назначения: "<<z.naznachenie <<endl;  
	cout<<"Время отправления: "<<z.time_o <<endl;  
	cout<<"Время прибытия: "<<z.time_p <<endl;  
	cout<<"Стоимость билета: "<<z.price <<endl; 
	cout<<"Номер поезда: " <<z.nomer <<endl; 
} 
//----------------------------просмотр очереди--------------------------- 
void prosmotr(zakaz *beg)  
{ 
	if (!beg) 
	{ 
		cout<<"Очередь пустая"<<endl; 
		cout<<"Нажмите любую клавишу"<<endl;   
		cin.get(); 
		return;  
	}  
	zakaz *temp=beg;
	cout<<"=============================="<<endl;  
	while (temp) 
	{   
		print(*temp);
		cout<<"=============================="<<endl;   
		cout<<"Нажмите любую клавишу"<<endl;   
		cin.get();   
		temp=temp->next;
	} 
} 
// ------------------------------чтение из файла----------------------------- 
int read_file(char* filename,zakaz** beg, zakaz** end)  
{ 
	ifstream fin(filename,ios::in);
	if (!fin) { cout<<"Нет файла" <<filename<<endl; return 1;}   
	zakaz z;  
	*beg = 0;  
	while (fin.getline(z.otpravlenie,d_o))
    {    
		fin.getline(z.naznachenie,d_n);    
		fin>>z.time_o;     
		fin>>z.time_p; 
		fin>>z.price; 
		fin>>z.nomer;      
		fin.get();         
		if (*beg) *beg=dob(*beg,z);      
		else      
		{ *beg=dob_first(z); *end=*beg; }
	}  
	return 0; 
} 
// ----------------------------запись в файл ---------------------------- 
int write_file(char* filename, zakaz* temp)  
{ 
	ofstream fout(filename); 
	if (!fout) {cout<<"Не могу открыть файл для записи"<<endl; return 1;}  
	while (temp) 
	{  
		fout<<temp->otpravlenie <<endl;    
		fout<<temp->naznachenie <<endl;    
		fout<<temp->time_o <<endl;     
		fout<<temp->time_p <<endl;
		fout<<temp->price <<endl; 
		fout<<temp->nomer <<endl;
		temp=temp->next;
	}  
	cout<<"Данные сохранены в файле: "<<filename<<endl;  
	cin.get();  
	return 0; 
} 
// -------------------добавление элемента в конец------------------------
zakaz* add_end(zakaz *beg,const zakaz& z) 
{
	zakaz *temp=beg;
	zakaz *newE = new zakaz;
	newE->next = NULL;
	while (!temp->next == NULL) 
	{
		temp = temp->next;
	}
	temp->next = newE;
}
