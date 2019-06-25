#include <iostream>
using namespace std;
 
int main()
{
	setlocale(0, "rus");
    int n;
    cout<<"Введите факториал:"<<endl; cin>>n;
    
    int maxsize=200;
    int a[maxsize],c=0;
    
    for(int i=0;i<200;++i) a[i]=0;
    a[199]=1;
    
    for(int i=1;i<=n;++i)
    	for(int j=199;j>=0;j--)
		{
	        a[j]=a[j]*i+c;
	        c=a[j]/10;
	        a[j]=a[j]%10;
        }
        
    int i,j;
    for(i=0;i<200;++i)
        if(a[i]!=0) break;
    
    cout<<"Результат:"<<endl;
    for(j=i;j<200;++j) cout<<a[j];
}
