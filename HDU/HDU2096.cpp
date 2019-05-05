#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a , b , x , y , p , q , t;
	scanf("%d" , &t);
	while(t--)
	{
		scanf("%d %d" , &a , &b);
		a = a % 100;
		b = b % 100;
		printf("%d\n" , (a+b)%100);
	}
	return 0;
 } 
