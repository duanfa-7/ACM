#include <stdio.h>
#include <iostream>
using namespace std;
int fun(int n , int x)
{
	if(n == 1)
	{
		return x;
	}
	else
	{
		return fun(n - 1 , (x + 1) *2);
	}
}
int main ()
{
	int n;
	while(cin >> n)
	{
		cout << fun( n , 1) << endl;
	}
	return 0;
}
