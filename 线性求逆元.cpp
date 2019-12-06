#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int A[100001];
int p;
int main()
{
	cin>>p;
	A[1]=1;
	for(int i=2;i<=10;i++)
		{
			A[i]=(p-(p/i))*A[p%i]%p;
			printf("%d %d %d\n",i,A[i],(i*A[i])%p);
		}
}

