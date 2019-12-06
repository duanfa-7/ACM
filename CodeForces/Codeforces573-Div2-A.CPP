#include <bits/stdc++.h>
using namespace std;
char judge(int a)
{
	if(a == 0) return 'D';
	else if(a == 1) return 'A';
	else if(a == 3) return 'B';
	else if(a == 2) return 'C';
}
int main()
{
	int n;
	scanf("%d" , &n);
	int t = 0 , we = t;
	int ans = n%4;
	char ch = judge(ans);
	while(t <= 2)
	{
		int op = (n+t)%4;
		char c = judge(op);
		if((ch-'0') >= (c-'0'))
		{
			we = t;
			ch = c;
		}
		t++;
	}
	cout << we << " " << ch<<endl;
	return 0;
 } 