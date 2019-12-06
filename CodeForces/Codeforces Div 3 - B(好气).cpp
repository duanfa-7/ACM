#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
const int maxn = 2008;
using namespace std;
 int main()
 {
 	int n , k  , a[maxn] , b[maxn] , book[maxn] , c[maxn] , t=1 , ans = 0 , ret = 0;
 	scanf("%d %d" , &n , &k);
 	memset(book , 0 , sizeof(book));
 	for(int i = 1 ; i <= n ; i++)
 	{
 		scanf("%d" , &a[i]);
 		b[i] = a[i];
	 }
	 sort(a+1 , a+n+1);
	 for(int i = n ; i > n-k ;i--)
	 {
	 	ret+=a[i];
	 	book[a[i]]++;	
	 }
	 printf("%d\n" , ret);
	
	 for(int i = 1 ; i <= n ; i++)
	 {
		 if(book[b[i]] > 0)
		 {
		 	book[b[i]]--;
		 	c[t++]=i;
		 } 
	 }
	if(k == 1)
	 {
	 	printf("%d\n" , n);
	  } 
	  else
	  {
	  	printf("%d " , c[1]);
		 for(int i = 1 ; i < t-2 ; i++)
		 {
		 	printf("%d " ,c[i+1]-c[i]);
		 }
		 printf("%d\n" , n-c[t-2]);

	  }
 	return 0;
 }
