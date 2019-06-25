#include <fstream> 
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <time.h> 
#include <iomanip> 
#include <conio.h> 
#include <iostream> 
using namespace std; 
//----------------------константы----------------------------------------- 
const int d_on=80;
//---------------------структуры------------------------------------------- 
struct zakaz
{
	int nomer;
	char otp_naz[d_on];    
	float price, time_o, time_p;
}; 
struct node     
{ 	zakaz data; 
	node* left;  
	node* right;  
}; 
//-------------прототипы функций-------------------------------------- 
node* addtree(node *top,const zakaz& newnode);
int menu();
int node_count(node *top,int level,int &n); 
void otobr(node *top, int otstup);
void prosmotr(node *top); 
int write_file(ofstream &f, node* top);
int read_file(char* filename, node* &top);
zakaz vvod();
//-------------------------основная функция------------------------------ 
int main() 
{      
	setlocale(0,"RUS"); 
	node *top=0;       
	char *filename="aero.txt";      
	ofstream fout;   //объявление выходного потока       
	read_file(filename,top);  //чтение данных из файла и создание дерева       
	while (1)        
	{   
		switch (menu())
		{
			case 1:       
				top=addtree(top,vvod());      
				break;  
			case 2:    
				otobr(top,1);      
				cout<<"Нажмите любую клавишу "<<endl; cin.get();      
				break;  
			case 3:    
				prosmotr(top);      
				cout<<"Нажмите любую клавишу "<<endl; cin.get();      
				break;  
			case 4:    
				{
					int level;     
					int n=0;      
					cout<<"Введите значение уровня"<<endl;      
					cin>>level;         
					cout<<"На данном уровне:"<<node_count(top,level,n)<<"вершин"<<endl;      
					cout<<"Нажмите любую клавишу "<<endl; cin.get();      
		  			break;  
	  			}
	  		case 5:    
	  			fout.open(filename);     
	  			if (!fout){cout<<"Ошибка открытия файла"<<endl; return 1;}      
	  			write_file(fout,top);   
	  			cout<<"Данные сохранены в файле: "<<filename<<endl;      
	  			cout<<"=============================="<<endl;      
	  			fout.close();      
	  			cout<<"Нажмите любую клавишу "<<endl; cin.get();      
	  			break;  
	  		case 6:     
	  			return 0;  
	  		default:   
	  			cout<<"Вам следует ввести число от 1 до 6"<< endl; cin.get();      
	  			break;  
	  }       
	} 
} 
//-----------------------добавление узла в дерево------------------------- 
node* addtree(node *top,const zakaz& newnode)  
{ 
	if (!top)       //если находимся на уровне листа,   
	{
		top=new node;   //то выделить память под узел   
		if (!top) 
		{
			cout<<"Не хватает памяти"<<endl; 
			return NULL;  
		}   
		top->data=newnode;  //запись данных в узел   
		top->left=NULL;   //обнуление указателей   
		top->right=NULL;  
	}  
	else 
		if (strcmp(top->data.otp_naz,newnode.otp_naz)>0) //сравниваем значение в узле с добавляемым   
			top->left=addtree(top->left,newnode); //добавляем в левое поддерево   
		else top->right=addtree(top->right,newnode);//или правое поддерево 
	return top;     //возвращаем указатель на корень дерева 
} 
// ----------------отображение структуры дерева--------------------------- 
void otobr(node *top, int otstup)  
{ 
	if (top)    
	{
		otstup+=3;     //отступ от края экрана   
		otobr(top->right,otstup);  //обход правого поддерева 
		cout<<setw(otstup)<<'*'<<top->data.otp_naz<<endl;   
		otobr(top->left,otstup);   //обход левого поддерева  
	} 
} 
// ----------------просмотр дерева---------------------------------------- 
void prosmotr(node *top)     //просмотр сверху вниз 
{ 
	if (top)    
	{
		cout<<top->data.otp_naz<<endl; 
		cout<<top->data.nomer<<endl;   
		cout<<top->data.price<<endl;
		cout<<top->data.time_o<<endl;
		cout<<top->data.time_p<<endl;
		prosmotr(top->left);   //обход левого поддерева   
		prosmotr(top->right);   //обход правого поддерева  
	} 
} 
//-------------------ввод данных------------------------------------------ 
zakaz vvod()  
{ 
	zakaz p;  
	cout<<"Введите пункт отправления-пункт назначения"<<endl;  
	cin.getline(p.otp_naz,d_on);  
	cout<<"Введите номер рейса"<<endl;  
	cin>>p.nomer;
	cout<<"Введите время отправления"<<endl;  
	cin>>p.time_o;
	cout<<"Введите время прибытия"<<endl;  
	cin>>p.time_p;
	cout<<"Введите цену"<<endl;  
	cin>>p.price;
	return p; 
} 
//---------------отображение и ввод пунктов меню----------------- 
int menu()  
{ 
	char buf[10];  
	int item;  
	do     
	{
		system("CLS");      
		cout<<"1- Добавить элемент в дерево"<<endl;     
		cout<<"2- Отобразить структуру дерева"<<endl;     
		cout<<"3- Просмотр дерева"<<endl;     
		cout<<"4- Поиск элемента"<<endl;     
		cout<<"5- Запись данных в файл"<<endl;     
		cout<<"6- Выход"<<endl;     
		cout<<"============================"<<endl; 
		cout<<"Введите номер пункта меню"<<endl;     
		cin>>buf;      //ввод номера пункта     
		cin.get();     
		item=atoi(buf);     //преобразовать его в целое     
		if (!item)       //если ошибка         
		{  
			cout<<"Вам следует ввести число от 1 до 6"<<endl;            
			cin.get();        
		}  
	} 
	while (!item);  //повторять пока не будет введено правильно   
	return item;  //вернуть номер введенного пункта меню
}
//----------подсчет узлов на заданном уровне дерева------------- 
int node_count(node *top,int level,int &n)
{
	if ((level>=1)&&top)     
	{ 
		if (level==1) n++;    //увеличить счетчик, если на уровне level есть вершина.  
		n=node_count(top->left,level-1,n); //подсчет узлов в левом поддереве   
		n=node_count(top->right,level-1,n);//подсчет узлов в правом поддереве  
	}  
	return n; 
} 
// -----------------------------чтение файла------------------------------ 
int read_file(char* filename, node* &top )  
{ 
	ifstream fin(filename,ios::in);
	if (!fin) {cout<<"Не найден файл"<<filename<<endl; return 1;} 
	zakaz p; 
	top = 0;  
	while (fin.getline(p.otp_naz,d_on))
	{       
		fin>>p.nomer;   
		fin>>p.time_o;  
		fin>>p.time_p;  
		fin>>p.price;  
		top=addtree(top,p);
	}  
	return 0; 
} 
// --------------------запись данных в файл------------------------------- 
int write_file(ofstream &f, node* top)  
{ 
	if (top)       
	{  
		f<<top->data.otp_naz<<endl;  //запись корня под(дерева)        
		f<<top->data.nomer<<endl;  
		f<<top->data.time_o<<endl;
		f<<top->data.time_p<<endl;
		f<<top->data.price<<endl;
		write_file(f,top->left);  //запись левого поддерева        
		write_file(f,top->right);  //запись правого поддерева     
	}  
	return 0; 
}
