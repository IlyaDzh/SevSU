#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	string s;
	string search = "char";
	string replace = "int";
	int count = 0;
	int i = 0;
	
	cout << "Введите строку: " << endl; 
	getline(cin, s);
	
	cout << "Исходная строка: " << endl;
	cout<<s;
	
	size_t pos = 0;
    while ((pos = s.find(search, pos)) != string::npos) 
	{
		count++;
        s.replace(pos, search.length(), replace);
        pos += replace.length();
    }
	
	cout << "\nКоличество слов char в строке: " << count << endl;
	
	cout << "Результат: " << endl;
	cout<<s;
	
	return 0;
}
