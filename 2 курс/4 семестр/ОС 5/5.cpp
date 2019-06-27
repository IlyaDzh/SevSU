#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

struct page
{
	unsigned short int number;
	unsigned short int life;
	bool request;
	bool isMod;
};

void vvod(page * mas, unsigned short int mainMemorySize);
void vivod(page * mas, unsigned short int mainMemorySize);
void RANDOM(page * mas, unsigned short int mainMemorySize);
void FIFO(page * mas, unsigned short int mainMemorySize);

	_COORD csrPos ;
   HWND hCon = ( HWND ) GetStdHandle ( STD_OUTPUT_HANDLE );  

int main()
{

   
	srand(time(0));
	unsigned short int mainMemorySize = 0; bool chooseStrat;
	cout << " Vvedite razmer OP : "; cin >> mainMemorySize;

	page * mas = new page[mainMemorySize];
	vvod(mas, mainMemorySize);
	while (1)
	{
		system("CLS");
		vivod(mas, mainMemorySize);
		csrPos.X = 10;
		csrPos.Y = mainMemorySize + 5;
		SetConsoleCursorPosition (hCon, csrPos); cout << "Viberite strategiyu zamesheniya stranic (0 - RANDOM, 1 - FIFO) : ";  cin >> chooseStrat;
		switch (chooseStrat)
		{
			case true:
			{
				FIFO(mas, mainMemorySize);
				break;
			}
			case false:
			{
				RANDOM(mas, mainMemorySize);
				break;
			}
		}
	}
	csrPos.X=3;
	csrPos.Y=1;
	SetConsoleCursorPosition(hCon, csrPos);
	system("pause");
	return 1;
}

void vvod(page * mas, unsigned short int mainMemorySize)
{
	bool choose;
	cout << "Random requests and mod-sign? (1 - yes, 0 - no) : "; cin >> choose;
	switch (choose)
	{
		case true:
		{
			for (int i = 0; i < mainMemorySize; i++)
			{
				cout << "Vvedite nomer " << i + 1 << " virtualnoy stranici : "; cin >> mas[i].number;
				mas[i].life = 1;
				mas[i].request = rand() % 2;
				mas[i].isMod = rand() % 2;
			}
			break;
		}
		case false:
		{
			for (int i = 0; i < mainMemorySize; i++)
			{
				cout << "Vvedite nomer " << i + 1 << " virtualnoy stranici : "; cin >> mas[i].number;
				cout << "\nBili li k " << i + 1 << " virtualnoy stranice zaprosi? (1 - da/ 0 - net) : "; cin >> mas[i].request;
				cout << "\nBili li u " << i + 1 << " virtualnoy stranici modifikacii ? (1 - da / 0 - net) : "; cin >> mas[i].isMod;
				mas[i].life = 1;			
			}
			break;
		}
	}
}

void vivod(page * mas, unsigned short int mainMemorySize)
{
	int x1,x2,x3,x4,x5, y = 3;
	x1 = 4; x2 = 8; x3 = 32; x4 = 52; x5 = 65;
	csrPos.X=x1;
	csrPos.Y=y;
	SetConsoleCursorPosition(hCon, csrPos); cout << "#";
	csrPos.X=x2;
	SetConsoleCursorPosition(hCon, csrPos); cout << "Nomer virtualnoy str.";
	csrPos.X=x3;
	SetConsoleCursorPosition(hCon, csrPos); cout << "Vremya zhizni str.";
	csrPos.X=x4;
	SetConsoleCursorPosition(hCon, csrPos); cout << "Obrasheniya";
	csrPos.X=x5;
	SetConsoleCursorPosition(hCon, csrPos); cout << "Modifikaciya";
	y++;
	for (int i = 0; i < mainMemorySize; i++)
	{
		csrPos.X=x1;
		csrPos.Y=y+i;
		SetConsoleCursorPosition(hCon, csrPos); cout << i + 1;
		csrPos.X=x2;
		csrPos.Y=y+i;
		SetConsoleCursorPosition(hCon, csrPos); cout << mas[i].number;
		csrPos.X=x3;
		csrPos.Y=y+i;
		SetConsoleCursorPosition(hCon, csrPos); cout << mas[i].life;
		csrPos.X=x4;
		csrPos.Y=y+i;
		SetConsoleCursorPosition(hCon, csrPos); cout << mas[i].request;
		csrPos.X=x5;
		csrPos.Y=y+i;
		SetConsoleCursorPosition(hCon, csrPos); cout << mas[i].isMod;
	}
}

void RANDOM(page * mas, unsigned short int mainMemorySize)
{
	int chosen,x = 10 ,y = mainMemorySize + 7; bool readOrWrite;
	unsigned short int pageNumber;
	bool sameCall = false;
	csrPos.X=x;
	csrPos.Y=y;
	SetConsoleCursorPosition(hCon, csrPos); cout << "Chtenie ili zapis' (0 - read, 1 - write)? : "; cin >> readOrWrite;
	switch (readOrWrite)
	{
		case false:  // Если чтение страницы
		{
			csrPos.X=x;
			csrPos.Y=y+1;
			SetConsoleCursorPosition(hCon, csrPos); cout << " Vvedite nomer stranici : "; cin >> pageNumber;
			for (int i = 0; i < mainMemorySize; i++)
				if (pageNumber == mas[i].number) { chosen = i; sameCall = true; break; }
			if (sameCall)
			{
				mas[chosen].request = 1;
				for (int i = 0; i < mainMemorySize; i++) mas[i].life++;
				csrPos.X=25;
				csrPos.Y=18;
				SetConsoleCursorPosition(hCon, csrPos); cout << "Budet proizvedeno chtenie uzhe raspolozhennoy v OP " << chosen + 1<< " stranici"; system("pause");
			}
			else
			{
				chosen = rand() % mainMemorySize;
				mas[chosen].number = pageNumber;
				mas[chosen].life = 1;
				mas[chosen].request = 1;
				for (int i = 0; i < mainMemorySize; i++) if (i != chosen) mas[i].life++;
				csrPos.X=25;
				csrPos.Y=18;
				SetConsoleCursorPosition(hCon, csrPos); cout << "Dlya chteniya po strategii RANDOM vibrana " << chosen + 1 << " stranica"; system("pause");
			}
			break;
		}
		case true: // Если запись в страницу
		{
			cout << " Vvedite nomer stranici : "; cin >> pageNumber;
			for (int i = 0; i < mainMemorySize; i++)
				if (pageNumber == mas[i].number) { chosen = i; sameCall = true; break; }
			if (sameCall)
			{
				mas[chosen].isMod = 1;
				mas[chosen].request = 1;
				for (int i = 0; i < mainMemorySize; i++) mas[i].life++;
				csrPos.X=25;
				csrPos.Y=18;
				SetConsoleCursorPosition(hCon, csrPos); cout << "Budet proizvedena zapis uzhe raspolozhennoy v OP " << chosen + 1 << " stranici"; system("pause");
			}
			else
			{
				chosen = rand() % mainMemorySize;
				mas[chosen].number = pageNumber;
				mas[chosen].life = 1;
				mas[chosen].request = 1;
				mas[chosen].isMod = 1;
				for (int i = 0; i < mainMemorySize; i++) if (i != chosen) mas[i].life++;
				csrPos.X=25;
				csrPos.Y=18;
				SetConsoleCursorPosition(hCon, csrPos); cout << "Dlya zapisi po strategii RANDOM vibrana " << chosen + 1 << " stranica"; system("pause");
			}
			break;
		}
	}
}

void FIFO(page * mas, unsigned short int mainMemorySize)
{
	int chosen, x = 10, y = mainMemorySize + 7; bool readOrWrite;
	unsigned short int pageNumber;
	bool sameCall = false, different = false;
	csrPos.X=x;
	csrPos.Y=y;
	SetConsoleCursorPosition(hCon, csrPos); cout << "Chtenie ili zapis' (0 - read, 1 - write)? : "; cin >> readOrWrite; system("pause");
	switch (readOrWrite)
	{
		case false:  // Если чтение страницы
		{
			csrPos.X=x;
			csrPos.Y=y+1;
			SetConsoleCursorPosition(hCon, csrPos); cout << " Vvedite nomer stranici : "; cin >> pageNumber;
			for (int i = 0; i < mainMemorySize; i++)
				if (pageNumber == mas[i].number) { chosen = i; sameCall = true; break; }
			if (sameCall)
			{
				mas[chosen].request = 1;
				for (int i = 0; i < mainMemorySize; i++) mas[i].life++;
				csrPos.X=25;
				csrPos.Y=18;
				SetConsoleCursorPosition(hCon, csrPos); cout << "Budet proizvedeno chtenie uzhe raspolozhennoy v OP " << chosen + 1 << " stranici"; system("pause");
			}
			else
			{
				chosen = 0;
				for (int i = 0; i < mainMemorySize; i++) // Для проверки, разное ли время жизни у всех страниц
				{
					if (mas[chosen].life != mas[i].life) different = true;
				}
				
				if (!different) // Если время жизни страниц одинаковое
				{
					for (int i = 0; i < mainMemorySize; i++)
					{
						if ((mas[i].request == 0) && (mas[i].isMod == 0)) { chosen = i; break; }
						else if (mas[i].request == 0) chosen = i;
					}
				}
				else
				{
					chosen = 0;
					for (int i = 0; i < mainMemorySize; i++) // Поиск самого старого
					{
						if (mas[chosen].life < mas[i].life) chosen = i;
					}
					bool best = false, medium = false, worst = false;
					for (int i = 0; i < mainMemorySize; i++) // Поиск самого не активного
					{
						if ((mas[chosen].life = mas[i].life) && (mas[i].request == 0) && (mas[i].isMod == 0)) { best = true; chosen = i; break; } // Старый && в последнее время не использовался && не модифицированный
						else if ((mas[chosen].life <= mas[i].life) && (mas[i].request == 0)) { chosen = i; continue; } // старый && в последнее время не использовался
					}
				}
				csrPos.X=25;
				csrPos.Y=18;
				SetConsoleCursorPosition(hCon, csrPos); cout << "Dlya chteniya po strategii FIFO vibrana " << chosen + 1 << " stranica"; system("pause");
				mas[chosen].number = pageNumber;
				mas[chosen].life = 1;
				mas[chosen].request = 1;
				for (int i = 0; i < mainMemorySize; i++) if (i != chosen) mas[i].life++;
			}
			break;
		}
		case true: // Если запись в страницу
		{
			cout << " Vvedite nomer stranici : "; cin >> pageNumber;
			for (int i = 0; i < mainMemorySize; i++)
				if (pageNumber == mas[i].number) { chosen = i; sameCall = true; break; }
			if (sameCall)
			{
				mas[chosen].isMod = 1;
				mas[chosen].request = 1;
				for (int i = 0; i < mainMemorySize; i++) mas[i].life++;
				csrPos.X=25;
				csrPos.Y=18;
				SetConsoleCursorPosition(hCon, csrPos); cout << "Budet proizvedena zapis' uzhe raspolozhennoy v OP " << chosen + 1 << " stranici"; system("pause");
			}
			else
			{
				chosen = 0;
				for (int i = 0; i < mainMemorySize; i++) // Для проверки, разное ли время жизни у всех страниц
				{
					if (mas[chosen].life != mas[i].life) different = true;
				}

				if (!different) // Если время жизни страниц одинаковое
				{
					for (int i = 0; i < mainMemorySize; i++)
					{
						if ((mas[i].request == 0) && (mas[i].isMod == 0)) { chosen = i; break; }
						else if (mas[i].request == 0) chosen = i;
					}
				}
				else
				{
					chosen = 0;
					for (int i = 0; i < mainMemorySize; i++) // Поиск самого старого
					{
						if (mas[chosen].life < mas[i].life) chosen = i;
					}
					bool best = false, medium = false, worst = false;
					for (int i = 0; i < mainMemorySize; i++) // Поиск самого не активного
					{
						if ((mas[chosen].life = mas[i].life) && (mas[i].request == 0) && (mas[i].isMod == 0)) { best = true; chosen = i; break; } // Старый && в последнее время не использовался && не модифицированный
						else if ((mas[chosen].life <= mas[i].life) && (mas[i].request == 0)) { chosen = i; continue; } // старый && в последнее время не использовался
					}
				}
				csrPos.X=25;
				csrPos.Y=18;
				SetConsoleCursorPosition(hCon, csrPos); cout << "Dlya zapisi po strategii FIFO vibrana " << chosen + 1 << " stranica"; system("pause");
				mas[chosen].number = pageNumber;
				mas[chosen].isMod = 1;
				mas[chosen].life = 1;
				mas[chosen].request = 1;
				for (int i = 0; i < mainMemorySize; i++) if (i != chosen) mas[i].life++;
			}
			break;
		}
	}
}

