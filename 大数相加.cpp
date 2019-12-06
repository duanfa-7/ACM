#include <iostream>
using namespace std;
int main()
{
	string a , b;
	cin >> a >> b;
	
	int aa[1000];
	int q = 0 , w = 0;
	if(a.length()<b.length())
	{
		string t=a;
		a=b;
		b=t;
	}
	for(int i=a.length()-1,j=b.length()-1;i>=0;i--,j--)
	{
		if(j>= 0)
		{
			aa[q++] = (a[i]-'0')+(b[j]-'0');
		}
		 else
		 {
		 	aa[q++] = a[i]-'0';
		 }
	}
	for(int i = 0; i < q-1; i++)
	{
	//printf("%d" , aa[i]);
		if(aa[i] > 9)
		{
			aa[i]-=10;
			aa[i+1]+=1; 
		}
	}
		if(aa[q-1] > 9 )
		{
			
			aa[q-1]-=10;
			aa[q] += 1;
			for(int i = q ; i>= 0 ; i--)
			{
				printf("%d" , aa[i]);
			}
		}
		else
		{
			for(int i = q-1 ; i>= 0 ; i--)
			{
				printf("%d" , aa[i]);
			}
		}
		
		printf("\n"); 
 } 

 /*//////////Íò¶ñµÄpython
 a = int(input())
b = int(input())
print a+b 
 */ 
