#include <conio.h>
#include <math.h>
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <iomanip> 
using namespace std;

int main()
{
	double Fn, Gn, ATg_FG, ATg_GF, pi, Nbegin, Nend, step, phi, k, Delta, Theta, O_large, ii;
	FILE *stream;
	
	stream = fopen("Example_TA.txt", "a+");
	cout << "Input Nbegin "; cin >> Nbegin;
	cout << "Input Nend "; cin >> Nend;
	cout << "Input step "; cin >> step;
	cout << "Input koefficient"; cin >> k;
	phi = M_PI / k;
	ii = Nbegin;
	while (ii <= Nend)
	{
		Fn = 2.5*pow(ii,2)+6*ii;
		Gn = 7.5*ii*sqrt(ii)+22*ii;
		ATg_FG = atan(Fn / Gn);
		ATg_GF = atan(Gn / Fn);
		pi = ATg_FG - ATg_GF;
		Delta = phi - pi;
		Theta = fabs(pi) - phi;
		O_large = pi + phi;
		fprintf(stream, "%f %f %f %f %f %f %f %f %f\n", ii, Fn, Gn, ATg_FG, ATg_GF, pi, Delta, Theta, O_large);
		ii = ii + step;
	}
	fclose(stream);
}
