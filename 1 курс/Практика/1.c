#include <conio.h>
#include <stdio.h>

int main()
{
	char c;
	FILE *f1=fopen("in.txt", "r");
	FILE *f2=fopen("out.txt", "w");
	if (!f1 && !f2)
	{
		puts("Can't open file\n");
		return 1;
	}
	while (fscanf(f1, "%c", &c)!=EOF)
	{
		if (c!='A') fprintf (f2, "%c", c);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}
