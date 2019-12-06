#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	string  s1 , s2;
	int flag = 0;
	s1 = "";
	cin >> s2;
		if(s2[0] == '-')
		{
			flag = 1;
			cout << "fu" << " ";
		}
		if(flag == 0)
		{
			for(int i = 0 ; i < s2.length() ; i++)
			{
				switch(s2[i])
				{
					case '0':s1 += "ling" ; break;
					case '1':s1 += "yi" ; break;
					case '2':s1 += "er" ; break;
					case '3':s1 += "san" ; break;
					case '4':s1 += "si" ; break;
					case '5':s1 += "wu" ; break;
					case '6':s1 += "liu" ; break;
					case '7':s1 += "qi" ; break;
					case '8':s1 += "ba" ; break;
					case '9':s1 += "jiu" ; break;
				}
				if(i != s2.length() - 1)
				{
					s1 += " ";
				}
			}
			cout << s1 ;
		}
		else
		{
			for(int i = 1; i < s2.length() ; i++)
			{
				switch(s2[i])
				{
					case '0':s1 += "ling" ; break;
					case '1':s1 += "yi" ; break;
					case '2':s1 += "er" ; break;
					case '3':s1 += "san" ; break;
					case '4':s1 += "si" ; break;
					case '5':s1 += "wu" ; break;
					case '6':s1 += "liu" ; break;
					case '7':s1 += "qi" ; break;
					case '8':s1 += "ba" ; break;
					case '9':s1 += "jiu" ; break;
				}
					if(i != s2.length() - 1)
				{
					s1 += " ";
				}
			}
			cout << s1 ;
		}

	
	return 0;
}
