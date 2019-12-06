#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t , n , m;
	string str1 , str2 , str3;
	scanf("%d" , &t);
	for(int i = 1 ; i <= t ; i++)
	{
		scanf("%d %d" , &n , &m);
		cin >> str1 >> str2;
		int num = str2[0] - str1[0];
//		if(num < 0) num += 26;
		cin >> str3;
		printf("Case #%d: " , i);
		for(int j = 0 ; j < str3.length() ; j++)
		{
			cout << char((str3[j]-'A'-num +26)%26 + 65);
		}
		printf("\n");
	}
	return 0;
}