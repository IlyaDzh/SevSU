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
const int d_n=20,    //длина Ф.И.О.       
		  d_m=20,    //длина названия модели автомобиля       
		  d_w=80;    //длина строки описания работ 
 //-----------------------структура элемента----------------------------------------- 
struct zakaz  
{ 
	char name[d_n],   //Ф.И.О.           
	model[d_m],  //название модели автомобиля           
	work[d_w];   //описание работы  
 	time_t time;   //время приема заказа  
	float price;    //стоимость  
	zakaz* next;   //указатель на следующий элемент 
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
 	char *filename="123.txt";  //имя файла       
 	time_t now;      // текущее время       
 	tm t;      // дата       
 	read_file(filename,&beg, &end); //чтение данных из файла в очередь 
 	while (1)  
	{ 
		switch (menu())		//отобразить меню и сделать выбор     
		{ 
		case 1: if (beg)     //если очередь не пустая, 
			  		end=dob(end,vvod_zakaza()); 	//то добавляем элемент в конец,     
				else {     //иначе   
					  beg=dob_first(vvod_zakaza());//создаем первый элемент очереди.   
					  end=beg;     //указатели начала и конца равны   
					 }      
				break;  
		case 2: beg=udal(beg);    //печать и удаление элемента     
				now = time(0);    //получить текущее время в сек.      
				t = *(localtime(&now));  //преобразовать  в дату      
				cout<<"Дата выполнения заказа: " //вывод даты   
					<<t.tm_mday<<'.'<<t.tm_mon+1<<'.'<<1900+t.tm_year<<endl;      
				cout<<"Нажмите любую клавишу"<<endl;      
				cin.get();      
				break;  
		case 3: prosmotr(beg);    //просмотр очереди      
				break;  
		case 4: write_file(filename,beg);  //запись в файл      
				break;  
		case 5: return 0;  
		default:     //если неверно введен номер пункта      
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
	char buf[10];  
	zakaz z;  
	cout<<"Введите Ф.И.О."<<endl;  
	cin.getline(z.name,d_n);  
	cout<<"Введите модель автомобиля"<<endl;  
	cin.getline(z.model,d_m);  
	cout<<"Введите описание работы"<<endl;  
	cin.getline(z.work,d_w);  
	z.time=time(0);    //зафиксировать время в поле time  
	do       //проверка ввода числа   
	{  
		cout<<"Введите стоимость работы"<<endl;     
		cin>>buf;  
	} 
	while (!(z.price=(float)atof(buf)));  
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
		cout<<endl;     
		cout<<"===СИСТЕМА УЧЕТА ЗАКАЗОВ==="<<endl<<endl;     
		cout<<"1- Добавление элемента в очередь"<<endl;     
		cout<<"2- Печать и удаление элемента"<<endl;    
		cout<<"3- Просмотр очереди"<<endl; 
		cout<<"4- Запись данных в файл"<<endl;     
		cout<<"5- Выход"<<endl;     
		cout<<"============================"<<endl;     
		cout<<"Введите номер пункта меню"<<endl;     
		cin>>buf;     //прочитать введенное значение     
		cin.get();     
		item=atoi(buf);    //преобразовать его в целое     
		if (!item) 
		{    //анализ ошибки ввода                      
			cout<<"Вам следует вводить число от 1 до 5"<<endl;                     
			cin.get();                     
		}  
	} 
	while (!item);   //повторять пока не введет число  
	return item;   //вернуть номер введенного пункта меню 
} 
// -----------------------------печать заказа----------------------------- 
void print(const zakaz& z)  
{ 
	tm t=*(localtime(&z.time));  
	cout<<"Ф.И.О.: " <<z.name<<endl;  
	cout<<"Модель автомобиля: "<<z.model<<endl;  
	cout<<"Описание работ: "<<z.work<<endl;  
	cout<<"Дата  приема: "<<t.tm_mday<<'.'<<t.tm_mon+1<<'.'<<1900+t.tm_year<<endl;  
	cout<<"Стоимость: "<<z.price<<endl; 
} 
//----------------------------просмотр очереди--------------------------- 
void prosmotr(zakaz *beg)  
{ 
	if (!beg) 
	{ 
		cout<<"Очередь пустая"<<endl; 
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
	ifstream fin(filename,ios::in); //открытие файла  
	if (!fin) { cout<<"Нет файла"    //выход если нет файла   
					<<filename<<endl; return 1;}   
	zakaz z;  
	*beg = 0;  
	while (fin.getline(z.name,d_n))   //чтение фио пока не конец файла  
    {    
		fin.getline(z.model,d_m);   //чтение марки  автомобиля         
		fin.getline(z.work,d_w);   //чтение описания работы         
		fin>>z.time>>z.price;   //чтение времени и стоимости         
		fin.get();         
		if (*beg)     //если очередь не пустая,       
			*end=dob(*end,z);   //то добавляем элемент в конец,         
		else      //иначе      
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
		fout<<temp->name<<endl; //вывод фио        
		fout<<temp->model<<endl; //вывод марки автомобиля        
		fout<<temp->work<<endl; //вывод описания работ        
		fout<<temp->time<<' '<<temp->price<<endl; //время и стоимость        
		temp=temp->next;   //переместить указатель на след. эл-т  
	}  
	cout<<"Данные сохранены в файле: "<<filename<<endl;  
	cout<<"=============================="<<endl;  
	cout<<"Нажмите любую клавишу"<<endl;  
	cin.get();  
	return 0; 
} 
