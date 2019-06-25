#include <fstream> 
#include <cstdlib> 
#include <cstring> 
#include <iomanip> 
#include <conio.h> 
#include <iostream> 
#include <windows.h> 
using namespace std; 

const int d_f = 20; 

struct stud 
{ 
	char fio[d_f]; 
	int f, i, m; 
}; 
struct node 
{
	stud data; 
	node* left; 
	node* right; 
}; 

node* addtree(node *top, const stud& newnode); 
int menu(); 
int node_otl(node *top, int &n); 
void otobr(node *top, int otstup); 
void prosmotr(node *top); 
int write_file(ofstream &f, node* top); 
int read_file(char* filename, node* &top); 
stud vvod(); 

void FreeTree(node * top) 
{ 
	if (top)
	{
		if (top->left) FreeTree(top->left); 
		if (top->right) FreeTree(top->right); 
		delete top; 
	}
} 

int main() 
{ 
	setlocale(0, "Russian"); 
	node *top = 0; 
	char *filename = (char*) ("stud.txt"); 
	ofstream fout; 
	read_file(filename, top); 
	while (1) 
	{ 
		switch (menu()) 
		{ 
			case 1: 
			{ 
				top = addtree(top, vvod()); 
				break; 
			} 
			case 2: 
			{ 
				otobr(top, 1); 
				cout << "Нажмите любую клавишу " << endl; 
				cin.get(); 
				break; 
			} 
			case 3: 
			{ 
				FreeTree(top); 
				break; 
			} 
			case 4: 
			{ 
				cout << " Имя | Физика | История | Математика |" << endl; 
				prosmotr(top); 
				cout << "Нажмите любую клавишу " << endl; 
				cin.get(); 
				break; 
			} 
			case 5: 
			{ 
				int n = 0; 
				cout << node_otl(top, n) << " отличников" << endl; 
				cout << "Нажмите любую клавишу " << endl;
				cin.get(); 
				break; 
			} 
			case 6: 
			{ 
				fout.open(filename); 
				if (!fout) { 
					cout << "Ошибка открытия файла" << endl; return 1; 
				} 
				write_file(fout, top); 
				cout << "Данные сохранены в файле: " << filename << endl; 
				cout << "==============================" << endl; 
				fout.close(); 
				cout << "Нажмите любую клавишу " << endl; 
				cin.get(); 
				break; 
			} 
			case 7: return 0; 
			default: 
			{ 
				cout << "Вам следует ввести число от 1 до 7" << endl; 
				cin.get(); 
				break; 
			} 
		} 
	} 
} 

node* addtree(node *top, const stud& newnode) 
{ 
	if (!top) 
	{ 
		top = new node; 
		if (!top) { 
			cout << "Не хватает памяти" << endl; 
			return NULL; 
		} 
		top->data = newnode; 
		top->left = NULL; 
		top->right = NULL; 
	} 
	else 
	if (strcmp(top->data.fio, newnode.fio)>0) 
		top->left = addtree(top->left, newnode); 
	else 
		top->right = addtree(top->right, newnode); 
	return top; 
} 

void otobr(node *top, int otstup) 
{ 
	if (top) 
	{ 
		otstup += 3; 
		otobr(top->right, otstup); 
		cout << setw(otstup)<< '*' << top->data.fio << endl; 
		otobr(top->left, otstup); 
	} 
} 

void prosmotr(node *top) 
{ 
	if (top) 
	{ 
		cout << setw(12) << left << top->data.fio; 
		cout << setw(10) << left << top->data.f; 
		cout << setw(13) << left << top->data.i; 
		cout << setw(18) << left << top->data.m << endl; 
		prosmotr(top->left); 
		prosmotr(top->right); 
	} 
} 

stud vvod() 
{ 
	stud p; 
	cout << "Введите имя:" << endl; 
	cin.getline(p.fio, d_f); 
	cout << "Введите оценку по Физике:" << endl; 
	cin >> p.f; 
	cout << "Введите оценку по Истории:" << endl; 
	cin >> p.i; 
	cout << "Введите оценку по Математике:" << endl; 
	cin >> p.m; 
	return p; 
} 

int menu() 
{ 
	char key = 0;
	int point = 0;
	do 
	{ 
		system("cls"); 
		if (key==72)
		{
			if (--point<0) point=7;
		}
		else if (key==80)
		{
			if (++point>7) point=0;
		}
		cout << ((point==1)?'>':' ')<< "1- Добавить элемент в дерево" << endl; 
		cout << ((point==2)?'>':' ')<< "2- Отобразить структуру дерева" << endl; 
		cout << ((point==3)?'>':' ')<< "3- Удаление всех элементов дерева" << endl; 
		cout << ((point==4)?'>':' ')<< "4- Просмотр дерева" << endl; 
		cout << ((point==5)?'>':' ')<< "5- Подсчет количества отличников" << endl; 
		cout << ((point==6)?'>':' ')<< "6- Запись данных в файл" << endl; 
		cout << ((point==7)?'>':' ')<< "7- Выход" << endl; 
		key=getch();
	} while (key!=13 && key!=27);
	system ("cls");
	return key==13?point:7;
} 

int node_otl(node *top, int &n) 
{ 
	if (top) 
	{ 
		if (top->data.f == 5 && top->data.i == 5 && top->data.m == 5) n++; 
		n = node_otl(top->left, n); 
		n = node_otl(top->right, n); 
	} 
	return n; 
} 

int read_file(char* filename, node* &top) 
{ 
	ifstream fin(filename, ios::in); 
	if (!fin) { cout << "Не найден файл" << filename << endl; return 1; } 
	stud p; 
	top = 0; 
	while (fin.getline(p.fio, d_f)) 
	{ 
		fin>>p.f; 
		fin>>p.i; 
		fin>>p.m; 
		top = addtree(top, p); 
	} 
	return 0; 
} 

int write_file(ofstream &f, node* top) 
{ 
	if (top) 
	{ 
		f << top->data.fio << endl; 
		f << top->data.f << endl; 
		f << top->data.i << endl; 
		f << top->data.m << endl; 
		write_file(f, top->left); 
		write_file(f, top->right); 
	} 
	return 0; 
}
