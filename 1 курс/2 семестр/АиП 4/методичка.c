#include <stdio.h> 
#include <string.h> 
#include <conio.h> 

const int len_fio=15; 
struct person 
{ 
	char fio[len_fio];
	int year;
	float salary;
};
const int size_p=sizeof(person); //размер структуры

int create_file(FILE *fbin);
int sort_file(FILE *fbin);
int print_file(FILE *fbin);
int search_persons(FILE *fbin); 

int main() 
{ 
	FILE *fbin;  
	char c;  
	fbin=fopen("person.dat","r+b"); //Открытие существующего файла        
	//для чтения и записи в конец  
	if (!fbin) 
	{   
		fbin=fopen("person.dat","w+b"); //Создание нового файла         
		//для обновления    
		if(!fbin)
		{    
			puts("Не могу открыть (создать) файл\n");    
			return 1;   
		} 
	}

  while (1)       
  {  
	  clrscr();   
	  puts("1- Запись в файл");   
	  puts("2- Сортировка файла");   
	  puts("3- Вывод файла");   
	  puts("4- Поиск и вычисления");   
	  puts("5- Выход");   
	  puts("______________________________");   
	  puts("Введите номер пункта меню\n");   
	  c=getch();   
	  switch (c)                 
	  { 
		  case '1':create_file(fbin); break;   
		  case '2':sort_file(fbin); break;   
		  case '3':print_file(fbin); break;   
		  case '4':search_persons(fbin); break;   
		  case '5':return 0;         
	  }  
  } 
}

int create_file(FILE *fbin)
{  
	person elem; 
	fseek(fbin,0,SEEK_END); 
	puts("Ввод данных о сотрудниках");  
	puts("Для выхода введите символ *");  
	puts("_________________________________\n");  
	while (1) 
	{   
		puts("Введите Ф.И.О. (обязательно с инициалами)");   
		getline(elem.fio,len_fio);  
		if (!strcmp(elem.fio,"*"))   return 1;
		puts("Введите год рождения");   
		scanf("%i",&elem.year);
		puts("Введите зарплату");   
		scanf("%f",&elem.salary);
		fwrite(&elem,size_p,1,fbin);
	} 
} 

int print_file(FILE *fbin)
{  
	person elem;  
	int n; 
	clrscr();  
	rewind(fbin);   //указатель в начало файла
	puts("Ф.И.О.         Год   Зарплата");  
	do 
	{   
		n=fread(&elem,size_p,1,fbin);	//чтение структуры из файла   
		if (n<1) break;    //если n<1, то конец файла   
		printf("%-15s%-6i%-8.2f\n",elem.fio,elem.year,elem.salary);       
	} 
	while (1); 
	puts("_____________________________");  
	puts("Нажмите любую клавишу");  
	getch();  
	return 0; 
} 

int sort_file(FILE *fbin) 
{  
	long i,j;  
	person elem1,elem2; 
	puts("Для сортировки нажмите любую клавишу");  
	getch();  
	fseek(fbin,0,SEEK_END); //указатель в конец 
	long len=ftell(fbin)/size_p; //определяем длину файла  
	rewind(fbin);   //указатель в начало  
	//пузырьковая сортировка  
	for(i=len-1;i>=1;i--)     
		for (j=0;j<=i-1;j++) 
		{   
			fseek(fbin,j*size_p,SEEK_SET);  //указатель на j-ую запись   
			fread(&elem1,size_p,1,fbin);  //читаем запись j в elem1   
			fread(&elem2,size_p,1,fbin);  //читаем след. запись в elem2   
			if (strcmp(elem1.fio,elem2.fio)>=1) 
			{   //сравниваем Ф.И.О.       
				fseek(fbin,(-2)*size_p,SEEK_CUR);   //указатель на 2 поз. назад       
				//обмен значений           
				fwrite(&elem2,size_p,1,fbin);  //сначала записываем elem2       
				fwrite(&elem1,size_p,1,fbin); // затем записываем elem1   
			}     
		}  
	puts("Для выхода нажмите любую клавишу");  
	getch();  
	return 0; 
}

int search_persons(FILE *fbin)
{  
	int not_found;   //флаг  поиска   
	char s[len_fio];   //строка для ввода фамилии  
	int n_persons=0;   //счетчик сотрудников  
	int n;  float summa_salary=0;  //сумма зарплат  
	person elem;  
	while (1) 
	{   
		puts("Введите фамилию или  * ");   
		cin.getline(s,len_fio);  //запоминаем фамилию в строке s   
		if (!strcmp(s,"*"))  break;  //выход, если ввели *   
		rewind(fbin);   //указатель в начало файла   
		not_found=1;   //флаг – сотрудник не найден   
		do 
		{     
			n=fread(&elem,size_p,1,fbin);  //читаем запись     
			if (n<1) break;    // если n<1, то конец файла     
			if (strstr(elem.fio,s))   //ищем строку s в поле fio       
			if (elem.fio[strlen(s)]==' ') 
			{
				//есть пробел после фамилии ?         
				strcpy(s,elem.fio);  //копируем fio в s         
				puts("_____________________________");         
				puts("Ф.И.О.         Год   Зарплата");         
				printf("%-15s%-6i%-8.2f\n",elem.fio,elem.year,elem.salary);         
				puts("_____________________________");         
				n_persons+=1;   //счетчик сотрудников         
				summa_salary+=elem.salary; //суммирование зарплат 
				not_found=0;    //сотрудник найден       
			}   
		} 
		while (1);   
		if (not_found)   puts("Такого сотрудника нет в файле");  
	}  
	if (n_persons>0)	printf("Средняя зарплата=%8.2f\n",summa_salary/n_persons);  
	puts("__________________________");  
	puts("Нажмите любую клавишу");  
	getch();  
	return 0; 
} 
