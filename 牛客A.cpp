#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int a , b , c  , x[5];
	while(~scanf("%d %d %d" , &a , &b , &c))
	{
		x[0] = a+b+c;
		x[1] = a*b*c;
		x[2] = (a+b) *c;
		x[3] = a * (b+c);
		int t = max(x[0] , max(x[1] ,max(x[2] , x[3])));
	//	sort(x , x+3);
		
		printf("%d\n" , t);
	}
	return 0;
 } 
