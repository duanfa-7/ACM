#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	string s1 , s2;
	while(cin >> s1)
	{
		int flag = 0;
		s2="";
		int a = 0 , b = 0;
		for(int i = 0 ; i < s1.length() ; i++)
		{
			if(s1[i] == '1')
			{
				a++;
			}
			if(flag == 0 && s1[i] == '0')
			{
				b++;
			}
			if(s1[i] =='2')
			{
				flag = 1;
				s2+='2';
			}
			if(flag == 1 && s1[i] == '0')
			{
				s2+='0';
			}
		}
		for(int i = 0 ; i < b ; i++)
		{
			printf("0");
		}
		for(int i = 0 ; i < a ; i++)
		{
			printf("1");
		}
		cout << s2 << endl;
	 } 
	return 0;
}
