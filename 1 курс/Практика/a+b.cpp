#include <iostream>
using namespace std;

const int maxsize = 100;
 
void vvod(int *mas)
{
    string s;
    cin >> s;
    for(int i=0; i<maxsize; ++i)
        mas[i] = 0;
 
    int len;
    len=s.length();
    for(int i=0; i<len; i++)
        mas[len - i] = int(s[i]) - '0';
}
 
void vivod(int *mas)
{
    int i = maxsize;
    while(mas[i] == 0 && i > 1) i--;
    for(int j=i; j>=1; j--) cout << mas[j];
}
 
int main()
{
	setlocale(0, "rus");
    int a[maxsize], b[maxsize];
    
 	cout << "¬ведите первое число:" << endl;
    vvod(a);
    cout << "¬ведите второе число:" << endl;
    vvod(b);
 
    int c = 0;
    for(int i=1; i<maxsize; ++i) 
    {
    	c = c + a[i] + b[i];
        a[i] = c % 10;
        c /= 10;
    }
 	cout << "–езультат:" << endl;
    vivod(a);
}
