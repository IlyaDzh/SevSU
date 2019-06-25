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
const int d_f=20, d_a=80;
//---------------------структуры------------------------------------------- 
struct gruz_p    // Описание  записи о грузополучателе  
{
	char fio[d_f], address[d_a];  
}; 
struct node   // Описание узла дерева         
{ 	gruz_p data; 
	node* left;  
	node* right;  
}; 
//-------------прототипы функций-------------------------------------- 
node* addtree(node *top,const gruz_p& newnode); //добавление узла 
int menu(); //отображение меню 
int node_count(node *top,int level,int &n); //подсчета количества вершин уровня
void otobr(node *top, int otstup); //отображение структуры дерева 
void prosmotr(node *top); //просмотр  значений узлов дерева слева направо 
int write_file(ofstream &f, node* top);  //запись в файл 
int read_file(char* filename, node* &top); //чтение из файла 
gruz_p vvod(); //ввод данных 
//-------------------------основная функция------------------------------ 
int main() 
{      
	node *top=0;       
	char *filename="gruz.txt";      
	ofstream fout;   //объявление выходного потока       
	read_file(filename,top);  //чтение данных из файла и создание дерева       
	while (1)        
	{   
		switch (menu())
		{
			case 1:       
				top=addtree(top,vvod()); //ввод и  добавление элемента        
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
				int level;     
				int n=0;      
				cout<<"Введите значение уровня"<<endl;      
				cin>>level;    
				cin.get();      
				cout<<"На данном уровне:"<<node_count(top,level,n)<<"вершин"<<endl;      
				cout<<"Нажмите любую клавишу "<<endl; cin.get();      
	  			break;  
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
node* addtree(node *top,const gruz_p& newnode)  
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
		if (strcmp(top->data.fio,newnode.fio)>0) //сравниваем значение в узле с добавляемым   
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
		cout<<setw(otstup)<<'*'<<top->data.fio<<endl;   
		otobr(top->left,otstup);   //обход левого поддерева  
	} 
} 
// ----------------просмотр дерева---------------------------------------- 
void prosmotr(node *top)     //просмотр сверху вниз 
{ 
	if (top)    
	{
		cout<<top->data.fio<<endl;  //вывод значения корня   
		cout<<top->data.address<<endl;   
		prosmotr(top->left);   //обход левого поддерева   
		prosmotr(top->right);   //обход правого поддерева  
	} 
} 
//-------------------ввод данных------------------------------------------ 
gruz_p vvod()  
{ 
	gruz_p p;  
	cout<<"Введите ф.и.о."<<endl;  
	cin.getline(p.fio,d_f);  
	cout<<"Введите адрес"<<endl;  
	cin.getline(p.address,d_a);  
	return p; 
} 
//---------------отображение и ввод пунктов меню----------------- 
int menu()  
{ 
	char buf[10];  
	int item;  
	do     
	{
		clrscr();     
		cout<<endl;     
		cout<<"==========ДЕРЕВЬЯ==========="<<endl<<endl;     
		cout<<"1- Добавить элемент в дерево"<<endl;     
		cout<<"2- Отобразить структуру дерева"<<endl;     
		cout<<"3- Просмотр дерева"<<endl;     
		cout<<"4- Подсчет узлов на заданном уровне"<<endl;     
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
	ifstream fin(filename,ios::in);   //открытие файла  
	if (!fin) {cout<<"Не найден файл"<<filename<<endl; return 1;} 
	gruz_p p; 
	top = 0;  
	while (fin.getline(p.fio,d_f))   //чтение ф.и.о. пока не конец файла  
	{       
		fin.getline(p.address,d_a); //чтение адреса         
		top=addtree(top,p);  //добавить эл-т в дерево  
	}  
	return 0; 
} 
// --------------------запись данных в файл------------------------------- 
int write_file(ofstream &f, node* top)  
{ 
	if (top)       
	{  
		f<<top->data.fio<<endl;  //запись корня под(дерева)        
		f<<top->data.address<<endl;         
		write_file(f,top->left);  //запись левого поддерева        
		write_file(f,top->right);  //запись правого поддерева     
	}  
	return 0; 
}
