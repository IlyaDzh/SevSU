#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include <algorithm>
#include <windows.h>
using namespace std;

class Book
{
public:
	string surname, date, number;
    Book(string _s, string _d, string _n)
    {
        surname = _s;
        date = _d;
        number = _n;
    }
    Book() {}
    ~Book() {}
    
    bool operator() (const Book &first, const Book &second)
    {
        return (first.surname < second.surname);
    }
};

int main()
{
	setlocale(0,"rus");
	
	Book b;
	list<Book> L;
	list<Book>::iterator iter;
	
	int n, count, N=0;
	while (1)
	{
		cout << "1 - Добавление в конец" << endl;
		cout << "2 - Добавление после" << endl;
		cout << "3 - Просмотр" << endl;
		cout << "4 - Удаление по ФИО" << endl;
		cout << "5 - Удаление всего списка" << endl;
		cout << "6 - Поиск по ФИО" << endl;
		cout << "7 - Сортировка" << endl;
		cout << "8 - Выход" << endl;
		cout << "Введите пункт меню: "; cin >> n;
		system("cls");
		switch (n)
		{
			case 1:
			{
				cout << "Введите количество записей: "; cin >> N;
				for (int i = 0; i < N; i++)
				{
					cout << "-----------------------------" << endl;
					cout<<"ФИО: "; cin>> b.surname; 
			        cout<<"Дата: "; cin>> b.date;
			        cout<<"Номер: "; cin>> b.number;
					L.push_back(b);
				}
				system("cls");
				break;
			}
			case 2:
			{
				int i=0; int in=0;
				if (L.empty()) cout<<"Список пустой"<<endl;
				else
				{
					cout << "Введите индекс: "; cin >> in;
					for (iter=L.begin(); iter != L.end(); ++iter)
					{
						if (i==in)
						{
							cout<<"ФИО: "; cin>> b.surname; 
					        cout<<"Дата: "; cin>> b.date;
					        cout<<"Номер: "; cin>> b.number;
							L.insert(iter, b);
						}
						i++;
					}	
				}
				system("pause");
				system("cls");
				break;
			}
			case 3:
			{
				int i = 0;
				if (L.empty()) cout<<"Список пустой"<<endl;
				else
				{
					for (iter=L.begin(); iter != L.end(); ++iter)
					{
						++i;
						cout << "Запись номер: " << i << endl;
						cout << (*iter).surname << endl;
						cout << (*iter).date << endl;
						cout << (*iter).number << endl;
						cout << "-----------------------------" << endl;
					}	
				}
				system("pause");
				system("cls");
				break;
			}
			case 4:
			{
				string fio; bool ll=false;
				if (L.empty()) cout<<"Список пустой"<<endl;
				else
				{
					cout << "Введите ФИО: "; cin >> fio;
					for (iter=L.begin(); iter!= L.end(); iter++)
					{
						if ((*iter).surname == fio) 
						{
							ll=true;
							L.erase(iter);
						}
					}
					if (!ll) cout<<"Не найдено"<<endl;
				}
				system("pause");
				system("cls");
				break;
			}
			case 5:
			{
				if (L.empty()) cout<<"Список пустой"<<endl;
				else L.clear();
				system("pause");
				system("cls");
				break;	
			}
			case 6:
			{
				string fio; bool ll=false;
				if (L.empty()) cout<<"Список пустой"<<endl;
				else
				{
					cout << "Введите ФИО: "; cin >> fio;
					for (iter=L.begin(); iter!= L.end(); iter++)
					{
						if ((*iter).surname == fio) 
						{
							ll=true;
							cout << (*iter).surname << endl;
							cout << (*iter).date << endl;
							cout << (*iter).number << endl;
							cout << "-----------------------------" << endl;
						}
					}
				if (!ll) cout<<"Не найдено"<<endl;
				}
				system("pause");
				system("cls");
				break;
			}
			case 7:
			{
				if (L.empty()) cout<<"Список пустой"<<endl;
				else L.sort(b);
				system("pause");
				system("cls");
				break;
			}
			case 8: return 0;
		}
	}
}
