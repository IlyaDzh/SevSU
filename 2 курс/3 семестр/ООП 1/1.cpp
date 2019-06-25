#include <fstream> 
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <time.h> 
#include <iomanip> 
#include <conio.h> 
#include <iostream> 
using namespace std; 

struct elem
{
	int number;
	string name;
	elem *next, *prev;
};

class product
{
private:
	elem * head, *tail;
public:
	product() : head(NULL), tail(NULL) {};
	
	product(product &cop)
	{
		elem *temp, *el;
		if (!cop.head) return;
		head = new elem;
		head->number = cop.head->number;
		head->name = cop.head->name;
		head->next = NULL;
		tail = head;
		temp = cop.head->next;
		while (temp)
		{
			el = new elem;
			tail->next = el;
			tail=el;
			tail->next = 0;
			tail->number = temp->number;
			tail->name = temp->name;
			temp = temp->next;
		}
	}
	
	~product()
	{
		elem *temp = head;
		while (head)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	}
	
	void vvod(elem *temp);
	void add_el();
	void vivod();
	void change();
	int sozdanie();
	void del();
	void poisk();
};

void product::vvod(elem *temp)
{
	cout << "Номер товара:" << endl;
	cin >> temp->number;
	cout << "Название товара:" << endl;
	cin >> temp->name;
}

void product :: change()
{
	int i = 1, n;
	elem *tmp;
	cout<<"Введите номер заменяемого поля:"<< endl;
	cin >> n;
	tmp = head;
	while (i!= n)
	{
		i++;
		tmp = tmp->next;
	}
	vvod(tmp);
}

int product :: sozdanie()
{
	char key;
	elem *newE;
	newE = new elem;
	vvod(newE);
	newE->next = head;
	head = newE;
	tail = newE;
	do
	{
		cout << "Добавить еще данные?" << endl;
		cout << "1 - Да" << endl;
		cout << "2 - Нет" << endl;
		cin >> key;
		switch (key)
		{
			case '1': add_el(); break;
			case '2': return 0;
		}
	} 
	while (1);
}

void product :: add_el()
{
    elem *newE  = new elem;
    vvod(newE);
    if (!head) 
	{
        newE -> next = tail;
        tail = newE;
    }
    else 
	{
        newE -> next = head;
        head -> prev = newE;
    }
    head = newE;
    head -> prev = NULL;
 
}

void product::vivod()
{
	elem *temp;
	temp = head;
	if (head)
	{
		while (temp)
		{
			cout << "  " << temp->number<< "               " << temp->name << endl;
			temp = temp->next;
		}
	}
}
void product :: del()
{
	elem *temp = 0;
	if (head)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	else cout << "Список пуст" << endl;
}

void product :: poisk()
{
    elem* temp2=head;
    int index, i;
    cout << "Введите номер для поиска:" << endl;
    cin >> index;
    while(temp2)
    {
        if(temp2->number==index) i++;
        temp2=temp2->next;
    }
    if (i!=0) cout << "Найдено" << endl;
    else cout << "Не найдено" << endl;
}

int main()
{
	setlocale(0, "rus");
	char key1, key2;
	product p1;
	cout << "Для создания списка введите данные." << endl;
	p1.sozdanie();
	product p2(p1);
	system("cls");
	while (1)
	{
		cout << "1 - Показать список" << endl;
		cout << "2 - Удалить товар" << endl;
		cout << "3 - Добавить товар" << endl;
		cout << "4 - Сменить товар" << endl;
		cout << "5 - Поиск товара" << endl;
		cout << "6 - Выход" << endl;
		cin >> key2;   
		switch (key2)
		{
			case '1':
			{    
				cout << "-------------------------------" << endl;
				cout << "| Номер    "<<"          Название |" << endl;
				cout << "|-----------------------------|" << endl;
				cout << "|          Оригинал:          |" << endl;
				cout << "|-----------------------------|" << endl;
				p1.vivod();
				cout << "|-----------------------------|" << endl;
				cout << "|           Копия:            |" << endl;
				cout << "|-----------------------------|" << endl;
				p2.vivod();
				cout << "------------------------------" << endl;
				system("pause");
				system("cls");
			}
				break;
			case '2':
			{   
				cout << "Где удалить элемент?" << endl;
				cout << "1 - Оригинал" << endl;
				cout << "2 - Копия" << endl;
				cin >> key1;
				switch (key1)
				{
					case'1':p1.del(); break;
					case'2':p2.del(); break;
				}
				system("pause");
				system("cls");
			}
				break;
			case '3':
			{
				cout << "Куда добавить элемент?" << endl;
				cout << "1 - Оригинал" << endl;
				cout << "2 - Копия" << endl;
				cin >> key1;
				switch (key1)
				{
					case'1':p1.add_el(); break;
					case'2':p2.add_el(); break;
				}
				system("pause");
				system("cls");
			} 
				break;
			case'4':
			{
				cout << "Где изменить элемент?" << endl;
				cout << "1 - Оригинал" << endl;
				cout << "2 - Копия" << endl;
				cin >> key1;
				switch (key1)
				{
					case'1':p1.change(); break;
					case'2':p2.change(); break;
				}
				system("pause");
				system("cls");
			} 
				break;
			case '5':
			{
				p1.poisk();
				system("pause");
				system("cls");
				break;
			} 
			case '6': return 0;
			default: cout << "Введите число от 1 до 6:" << endl;
		}
	}
}
