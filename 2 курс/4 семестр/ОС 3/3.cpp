#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std;

struct file_mas
{
    char name[9], type[4];
    int data_year, data_mon, data_day;
    int count_obr;
    int size;
    int time_hour, time_min;
} file;

void vvod(struct file_mas *file, int N);
void vivod(struct file_mas *file, int N);
void sort(struct file_mas *file, int N);

int main()
{
	setlocale(0,"RUS");
	char c; int N;
	cout<<"Введите размер массива структуры: "; cin>>N;
	file_mas *file = new file_mas[N];
	vvod(file, N);
	vivod(file, N);
	sort(file, N);
	vivod(file, N);
}

void vvod (struct file_mas *file, int N)
{
	cout << "\n----------ВВОД ДАННЫХ----------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "Название файла: "; cin >> gets(file[i].name);
		cout << "Тип файла: "; cin >> gets(file[i].type);
        cout << "Ввод даты создания." << endl;
        cout << "  День: "; cin >> file[i].data_day;
        cout << "  Месяц: "; cin >> file[i].data_mon;
        cout << "  Год: "; cin >> file[i].data_year;
        cout << "Кол-во обращений: "; cin >> file[i].count_obr;
        cout << "Размер файла: "; cin >> file[i].size;
        cout << "Время последней модификации." << endl;
        cout << "  Часы: "; cin >> file[i].time_hour;
        cout << "  Минуты: "; cin >> file[i].time_min;
        cout << "--------------------------------" << endl;
	}
}

void vivod (struct file_mas *file, int N)
{
	cout << "\n|------------------------------ВЫВОД ДАННЫХ------------------------------|" << endl;
	cout << "|------------------------------------------------------------------------|" << endl;
	cout << "| Название | Тип |     Дата     | Обращения | Размер | Время модификации |" << endl;
	cout << "|------------------------------------------------------------------------|" << endl;
	for (int i = 0; i < N; i++)
	{
		cout<< setw(10) << file[i].name 
			<< setw(6) << file[i].type 
			<< setw(6) << file[i].data_day << "." << file[i].data_mon << "." << file[i].data_year 
			<< setw(13) << file[i].count_obr 
			<< setw(9) << file[i].size 
			<< setw(17) << file[i].time_hour << ":" << file[i].time_min << endl;
        cout << "-------------------------------------------------------------------------" << endl;
	}
}

void sort (struct file_mas *file, int N)
{
	for (int i = 0; i< N-1; i++)      
	for (int j = 0; j<N-i-1; j++) 
	if (file[j].data_year > file[j+1].data_year || 
	  	file[j].data_year == file[j+1].data_year && 
	  	file[j].data_mon > file[j+1].data_mon ||
		file[j].data_year == file[j+1].data_year &&
	  	file[j].data_mon == file[j+1].data_mon &&
	  	file[j].data_day > file[j+1].data_day)
	{      
		char s1[9];
		strcpy(s1, file[j].name);
		strcpy(file[j].name, file[j+1].name);
		strcpy(file[j+1].name, s1);
		char s2[4];
		strcpy(s2, file[j].type);
		strcpy(file[j].type, file[j+1].type);
		strcpy(file[j+1].type, s2);
		int temp1= file[j].data_year;    
		file[j].data_year= file[j+1].data_year;    
		file[j+1].data_year = temp1;    
		int temp2= file[j].data_mon;    
		file[j].data_mon= file[j+1].data_mon;    
		file[j+1].data_mon = temp2;  
		int temp3= file[j].data_day;    
		file[j].data_day= file[j+1].data_day;    
		file[j+1].data_day = temp3;  
		int temp4= file[j].count_obr;    
		file[j].count_obr= file[j+1].count_obr;    
		file[j+1].count_obr = temp4;  
		int temp5= file[j].size;    
		file[j].size= file[j+1].size;    
		file[j+1].size = temp5;  
		int temp6= file[j].time_hour;    
		file[j].time_hour= file[j+1].time_hour;    
		file[j+1].time_hour = temp6; 
		int temp7= file[j].time_min;    
		file[j].time_min= file[j+1].time_min;    
		file[j+1].time_min = temp7; 
	} 
}
