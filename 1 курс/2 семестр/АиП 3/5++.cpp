#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    setlocale(0,"RUS");
    string s1, s[200], temp;
    int count = 0;
    ifstream f("1.txt", ios::in); 
    if (!f)
    {   cout<<"Не могу открыть файл!"<<endl; 
		return 1; 
    }
    while (getline(f, s1, ' ')) 
	{
        s[count] = s1;
        count++;
    }
    for (int i = 0; i<200; i += 2) 
	{
        temp = s[i];
        s[i] = s[i + 1];
        s[i + 1] = temp;
    }
    for (int i = 0; i<200; i++) 
	{
        cout << s[i] << " ";
    }
    f.close();
    return 0;
}
