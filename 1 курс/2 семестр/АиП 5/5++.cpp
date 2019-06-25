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
zakaz* dob(zakaz* end, const zakaz& z); //добавление элемента в очередь 
zakaz* dob_first(const zakaz& z);  //добавление первого элемента 
zakaz* udal(zakaz* beg);   //удаление элемента из очереди 
zakaz vvod_zakaza();    //ввод значений элемента 
int  menu();     //отображение меню и ввод его пункта 
void print(const zakaz& z);   //вывод значений  элемента 
void prosmotr(zakaz* beg);   //просмотр очереди 
int  read_file(char* filename, zakaz** beg, zakaz** end);  //чтение файла 
int  write_file(char* filename, zakaz* temp);   //запись в файл 
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
			  		end=dob(end,vvod_zakaza()); 	//то добавляем элемент в конец,     
				else {  
					  beg=dob_first(vvod_zakaza());//создаем первый элемент очереди.   
					  end=beg;     //указатели начала и конца равны   
					 }      
				break;  
		case 2: beg=udal(beg);        
				cout<<"Нажмите любую клавишу"<<endl;      
				cin.get();      
				break;  
		case 3: prosmotr(beg);  
				break;  
		case 4: write_file(filename,beg);   
				break;  
		case 5: return 0;  
		default:    
				cout<<"Вам следует ввести номер от 1 до 5"<< endl;      
				cin.get();      
				break;  
		}       
	} 
} 
//-----------------------добавление элемента----------------------------- 
zakaz* dob(zakaz *end,const zakaz& z)    //возвращает указатель на доб. эл-т 
{         
	zakaz *newE=new zakaz;  //выделение памяти под элемент  
	*newE=z;     //присвоить значения элементу  
	newE->next=0;    //ссылка на следующий эл-т нулевая   
	end->next=newE;   //добавить эл-т в очередь  
	end=newE;     //установить указатель end на newE   
	return end;     //вернуть измененное значение end 
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
		cout<<"1- Добавление элемента в очередь"<<endl;     
		cout<<"2- Удаление элемента"<<endl;    
		cout<<"3- Просмотр очереди"<<endl; 
		cout<<"4- Запись данных в файл"<<endl;     
		cout<<"5- Выход"<<endl;     
		cout<<"============================"<<endl;     
		cout<<"Введите номер пункта меню:"<<endl;     
		cin>>buf;    
		cin.get();     
		item=atoi(buf);    //преобразовать его в целое     
		if (!item) 
		{    //анализ ошибки ввода                      
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
	zakaz *temp=beg;  //указатель temp устанавливаем в начало  
	cout<<"=============================="<<endl;  
	while (temp) 
	{   //просматриваем пока temp!=0   
		print(*temp);  //печатаем значения элемента по указателю   
		cout<<"=============================="<<endl;   
		cout<<"Нажмите любую клавишу"<<endl;   
		cin.get();   
		temp=temp->next; //перемещаем temp на следующий эл-т  
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
		if (*beg)     //если очередь не пустая,       
			*end=dob(*end,z);   //то добавляем элемент в конец,         
		else      
		{ *beg=dob_first(z); *end=*beg; } //создаем первый элемент  
	}  
	return 0; 
} 
// ----------------------------запись в файл ---------------------------- 
int write_file(char* filename, zakaz* temp)  
{ 
	ofstream fout(filename);   //открытие файла  
	if (!fout) {cout<<"Не могу открыть файл для записи"<<endl; return 1;}  
	while (temp)     //пока temp!=0 выводим эл-ты в файл     
	{  
		fout<<temp->otpravlenie <<endl; //вывод станции отправления      
		fout<<temp->naznachenie <<endl; //вывод станции назначения       
		fout<<temp->time_o <<endl; //вывод времени отправления       
		fout<<temp->time_p <<endl; //вывод времени прибытия   
		fout<<temp->price <<endl; //вывод стоимости билета   
		fout<<temp->nomer <<endl; //вывод номера поезда
		temp=temp->next;   //переместить указатель на след. эл-т  
	}  
	cout<<"Данные сохранены в файле: "<<filename<<endl;  
	cin.get();  
	return 0; 
} 
