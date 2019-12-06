#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 int main()
 {
 	int a[1008] , n , b[1008];
 	scanf("%d" , &n);
 	for(int i = 0 ; i < n ; i++)
 	{
 		scanf("%d" , &a[i]);
 		if(a[i]%2==0)
 		{
 			b[i] =a[i]-1;
		 }
		 else
		 {
		 	b[i] =a[i];
		 }
	 }
 	for(int i = 0 ; i < n ; i++)
 	{
 		printf("%d " , b[i]);
	 }
	 printf("\n");
 	return 0;
 }
