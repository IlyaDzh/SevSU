#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int MATRIX_SIZE = 13;

const int matrix[MATRIX_SIZE][MATRIX_SIZE] = {
	//         1   2   3   4   5   6   7   8   9  10  11  12  13
	/* 1 */ {  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0 },
	/* 2 */ {  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	/* 3 */ {  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  0 },
	/* 4 */ {  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  0,  1 },
	/* 5 */ {  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	/* 6 */ {  1,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	/* 7 */ {  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	/* 8 */ {  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0 },
	/* 9 */ {  0,  0,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	/* 10*/ {  0,  0,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	/* 11*/ {  1,  1,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0 },
	/* 12*/ {  0,  0,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
	/* 13*/ {  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
};

void print_error(int error_code, int step, int last_true);
string error_code_to_message(int error_code, int last_true);
int numeric_to_code(int numeric);
string error_code_decryption(int error_code);
string numeric_to_symbol(int numeric);

int main()
{
	setlocale(LC_ALL, "Russian");

	vector<int> initial_array = {
		300, 508, 400, 507,
		300, 508, 400, 505, 300, 507,
		100, 503, 300, 504,
		501,
		200, 400, 509, 300, 508, 300, 505, 400, 507,
		200, 400, 509, 300, 508, 300, 505, 400, 507,
		502
	};

	cout << "> size = " << initial_array.size() << endl;

	vector<int> primary_array = initial_array;

	for (int i = 0; i < primary_array.size(); i++)
	{
		switch (primary_array[i])
		{
		case 100: { primary_array[i] = 1; break; }
		case 200: { primary_array[i] = 2; break; }
		case 300: { primary_array[i] = 3; break; }
		case 400: { primary_array[i] = 4; break; }
		case 501: { primary_array[i] = 5; break; }
		case 502: { primary_array[i] = 6; break; }
		case 503: { primary_array[i] = 7; break; }
		case 504: { primary_array[i] = 8; break; }
		case 505: { primary_array[i] = 9; break; }
		case 506: { primary_array[i] = 10; break; }
		case 507: { primary_array[i] = 11; break; }
		case 508: { primary_array[i] = 12; break; }
		case 509: { primary_array[i] = 13; break; }
		default: { break; }
		}
	}

	for (int i = 0; i < primary_array.size() - 1; i++)
	{
		int symbol = primary_array[i] - 1;
		int symbol_next = primary_array[i + 1] - 1;
		if (matrix[symbol][symbol_next] == 1)
		{
			continue;
		}
		else
		{
			print_error(numeric_to_code(symbol_next + 1), i, symbol + 1);
			system("pause");
			return -1;
		}
	}

	cout << "Корректное завершение" << endl;

	system("pause");

	return 0;
}

void print_error(int error_code, int step, int last_true)
{
	string error_message = error_code_to_message(error_code, last_true);
	string error_desc = error_code_decryption(error_code);
	cout << "Обнаружена ошибка. Шаг выполнения "
		<< step + 1 << endl
		<< error_desc << endl
		<< error_message << endl;
}

string error_code_to_message(int error_code, int last_true)
{
	string message;
	int target_number = last_true;
	switch (error_code)
	{
	case 100: { message = "Встречено служебное слово - SWITCH."; break; }
	case 200: { message = "Встречено служебное слово - CASE."; break; }
	case 300: { message = "Встречен идентификатор."; break; }
	case 400: { message = "Встречена константа."; break; }
	case 501: { message = "Встречен символ '{'."; break; }
	case 502: { message = "Встречен символ '}'."; break; }
	case 503: { message = "Встречен символ '('."; break; }
	case 504: { message = "Встречен символ ')'."; break; }
	case 505: { message = "Встречен знак '+'."; break; }
	case 506: { message = "Встречен знак '-'."; break; }
	case 507: { message = "Встречен символ ';'."; break; }
	case 508: { message = "Встречен оператор присваивания '='."; break; }
	case 509: { message = "Встречен символ ':'."; break; }
	default: { break; }
	}

	message = message + " Ожидалось: ";

	bool flag = false;
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		if (matrix[target_number - 1][i] == 1)
		{
			if (!flag)
			{
				message = message + numeric_to_symbol(i + 1);
				flag = true;
			}
			else
			{
				message = message + " / " + numeric_to_symbol(i + 1);
			}
		}
	}

	message = message + ".";

	return message;
}

int numeric_to_code(int numeric)
{
	int code = -1;
	switch (numeric)
	{
	case 1: { code = 100; break; }
	case 2: { code = 200; break; }
	case 3: { code = 300; break; }
	case 4: { code = 400; break; }
	case 5: { code = 501; break; }
	case 6: { code = 502; break; }
	case 7: { code = 503; break; }
	case 8: { code = 504; break; }
	case 9: { code = 505; break; }
	case 10: { code = 506; break; }
	case 11: { code = 507; break; }
	case 12: { code = 508; break; }
	case 13: { code = 509; break; }
	default: { break; }
	}
	return code;
}

string error_code_decryption(int error_code)
{
	string sym = "null";
	switch (error_code)
	{
	case 100: case 200: case 509: case 503: case 504: { sym = "Недопустимая конструкция языка."; break; }
	case 300: { sym = "Недопустимая комбинация идентификаторов."; break; }
	case 400: { sym = "Недопустимая комбинация констант."; break; }
	case 501: case 502: { sym = "Недопустимая комбинация операторных скобок."; break; }
	case 505: case 506: { sym = "Недопустимая комбинация знаков."; break; }
	case 507: { sym = "Недопустимое окончание выражения."; break; }
	case 508: { sym = "Недопустимое присваивание."; break; }
	default: { sym = "Неоределенная компановка кода."; break; }
	}
	return sym;
}

string numeric_to_symbol(int numeric)
{
	string sym = "null";
	switch (numeric)
	{
	case 1: { sym = "SWITCH"; break; }
	case 2: { sym = "CASE"; break; }
	case 3: { sym = "идентификатор"; break; }
	case 4: { sym = "константа"; break; }
	case 5: { sym = "{"; break; }
	case 6: { sym = "}"; break; }
	case 7: { sym = "("; break; }
	case 8: { sym = ")"; break; }
	case 9: { sym = "+"; break; }
	case 10: { sym = "-"; break; }
	case 11: { sym = ";"; break; }
	case 12: { sym = "="; break; }
	case 13: { sym = ":"; break; }
	default: { break; }
	}
	return sym;
}