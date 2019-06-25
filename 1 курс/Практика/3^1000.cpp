#include <iostream>
using namespace std;

main ()
{
	setlocale(0, "rus");
	int n;
    cout<<"Введите степень: "; cin>>n;
    string s="1";
    for(int i=0; i<n; i++)
    {
        int x=0;
        for(int k=s.length()-1; k>=0; k--)
        {
            x+=(s[k]-'0')*3;
            s[k]=x%10+'0';
            x/=10;
        }
        if(x) s=char(x+'0')+s;
    }
    cout<<"Результат: "<<s<<endl;
}
