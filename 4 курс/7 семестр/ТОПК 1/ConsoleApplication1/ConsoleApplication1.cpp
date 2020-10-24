#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

const int regex[2][7] = {
	{3, 2, -1, 5, 4, 5, 5},
	{1, 1, -1, 4, 4, 6, -1}
};

void validate(const char* string) {
	int count = 0;
	int i = 0;

	while (string[count] != '\n' && i != -1) {
		char c = string[count];

		switch (c) {
		case 'a': i = regex[0][i]; break;
		case 'b': i = regex[1][i]; break;
		default: i = -1; break;
		}

		printf("%c", c);
		count++;
	}
	printf("\nState = %d\n", i);

	int result = (i == -1 || i == 2 || i == 4 || i == 5 || i == 6) ? i : -2;

	printf("%s on length %d\n\n", result == -2 ? "Not full" : result == -1 ? "Invalid" : "Valid", count);
}

int main(int argc, char** argv) {
	char string[50];
	char* estr;
	FILE* file;
	file = fopen("input.txt", "r");

	if (file == NULL) {
		printf("File not found!\n");
		return -1;
	}

	while (1) {
		estr = fgets(string, sizeof(string), file);

		if (estr == NULL) {
			break;
		}

		validate(string);
	}

	fclose(file);

	return 0;
}