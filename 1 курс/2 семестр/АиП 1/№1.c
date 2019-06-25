#include <conio.h> 
#include <stdio.h> 
#include <math.h>
main() 
{   	setlocale(0,"RUS");
		float a, b, x, z, xn, xk, dx;   
    	printf("Введите параметр a: "); scanf("%f",&a);    
    	printf("Введите параметр b: "); scanf("%f",&b);   
    	printf("Введите xn: "); scanf("%f",&xn);     
    	printf("Введите xk: "); scanf("%f",&xk);     
    	printf("Введите шаг dx: "); scanf("%f",&dx);   
    	printf("Таблица значений функции z=f(x)\n");     
    	printf("  --------------------------\n");     
    	printf("  |     x     |  z = f(x)  |\n");     
    	printf("  |-----------|------------|\n");     
    	x=xn; 
    	while (x<=xk)   
    	{ 	printf("  |  %-9f|",x);
    		if (x<=a) z=log10(pow(pow(x,2), 1/3)+sqrt(x)+sin(x)+cos(x));
    		else if (a<x<b) z=pow((pow(tan(x),2)+1.3*exp(cosh(x)+tanh(x))),pow(x,2));
    		else z=abs(sin(x)-0.11)*acos(x)+pow(x,asin(x));
			printf("  %-10.6f|\n",z); 
    		x+=dx; 
    	}     
    	printf("  --------------------------\n");     
    	printf("Нажмите любую клавишу...");  
		getch(); 
    	return 0; 
}

