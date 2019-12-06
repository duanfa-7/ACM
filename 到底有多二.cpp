#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
	string s1;
	cin >> s1;
	double wq ;
	
	int len = s1.length() , ans = 0;
	
	 if(s1[0] == '-' &&( s1[len] - '0') % 2 == 0)
	{
			for(int i = 1 ; i < len ; i++)
		{
			if(s1[i] == '2')
			{
				ans++;
			}
		}
	//	printf("ans = %d , len = %d\n" , ans , len);
	double wq = (double) ans / (len - 1);
		printf("%.2f%%" , wq * 100 * 1.5 * 2);
	
	}
	else if(s1[0] == '-')
	{
		for(int i = 1 ; i < len ; i++)
		{
			if(s1[i] == '2')
			{
				ans++;
			}
		}
		double wq = (double) ans / (len - 1);
		printf("%.2f%%" , wq * 100 * 0.5 * 2);
		
	}
	else
	{
			for(int i = 0 ; i < len ; i++)
		{
			if(s1[i] == '2')
			{
				ans++;
			}
		}
	double wq = (double) ans / (len - 1);
		printf("%.2f%%" , wq * 100  * 2);
		
	}
	return 0;
 } 
