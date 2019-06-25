#include <iostream> 
#include <cmath>
using namespace std; 

class Progress
{
public:
	double *a;
	int len;
	
	Progress(int n) 
	{	 
		a=new double[n];	 
		len=n; 
	}
	
	virtual ~Progress()
	{
		delete[]a;
	}
	
	virtual double SumPr() = 0;
};

class ArPr : public Progress
{
private:
	double fa, d;
	
public:
	
	ArPr(int n, double _fa, double _d) : Progress(n)
	{
		fa=_fa; d=_d;
		for(int i=0; i<len; i++) 
		{
			a[i]=fa+i*d; 
			cout<<a[i]<<", ";
		} 
		cout<<endl;
	}
	
	virtual double SumPr()
	{
		double s=0;
		for(int i=0; i<len; i++) s+=(len+1)*(fa+a[i])/2;
		return s;
	}
	
};

class GeoPr : public Progress
{
private:
	double fg, r;
	
public:
	
	GeoPr(int n, double _fg, double _r) : Progress(n)
	{
		fg=_fg; r=_r;
		for(int i=0; i<len; i++) 
		{
			a[i]=fg*pow(r,i); 
			cout<<a[i]<<", ";
		} 
		cout<<endl;
	}
	
	virtual double SumPr()
	{
		double s=0;
		for(int i=0; i<len; i++) s+=(fg-a[i]*r)/(1-r);
		return s;
	}
	
};

int main ()
{
	double fa, d, fg, r, n;
	setlocale(0, "rus");
	
	cout<<"¬ведите размер: ";
	cin>>n;
	
	cout<<"¬ведите начальное значение: ";
	cin>>fa;
	cout<<"¬ведите посто€нную разность: ";
	cin>>d;
	Progress *ob = new ArPr(n, fa, d);
	cout<<"—умма арифм. прогрессии: "<<ob->SumPr()<<endl;
	delete ob;
	
	cout<<"--------------------------------------"<<endl;
	
	cout<<"¬ведите начальное значение: ";
	cin>>fg;
	cout<<"¬ведите посто€нное отношение: ";
	cin>>r;
	ob = new GeoPr(n, fg, r);
	cout<<"—умма геом. прогрессии: "<<ob->SumPr()<<endl;
	delete ob;
}
