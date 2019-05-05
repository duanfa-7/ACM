#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	char a[3];
	while(cin >> a[0] >> a[1] >> a[2])
	{
		sort(a , a+3);
		printf("%c %c %c" , a[0] , a[1] , a[2]);
		printf("\n");
	}
	return 0 ;
}

