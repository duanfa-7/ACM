#include <bits/stdc++.h>
using namespace std;
int main()
{
	map<char , int>M;
//	freopen("C:\\Users\\lenovo\\Desktop\\out.txt","w",stdout);
	M['A'] = 1;M['E'] = 2;M['H'] = 3;M['I'] = 4;M['J'] = 5;M['L'] = -5;M['M'] = 7;M['O'] = 8;M['S'] = 9;M['T'] = 10;
	M['U'] = 11;M['V'] = 12;M['W'] = 13;M['X'] = 14;M['Y'] = 15;M['Z'] = 16;M['1'] = 17;M['2'] = -9;M['3'] = -2;M['5'] = -16;
	M['8'] = 21;
	
	string str;
	while(cin >> str)
	{
		int len = str.length();	
		int l = 0 , r = len-1;
		int flag = 0;
		while(l <= r)
		{
			if(l == r)
			{
			
				if(M[str[l]] ==1||M[str[l]] == 3 ||M[str[l]] == 4 ||M[str[l]] == 7 ||M[str[l]] == 8 ||M[str[l]] == 10 ||
				M[str[l]] == 11 ||M[str[l]] == 12 ||M[str[l]] == 13 ||M[str[l]] == 14 ||M[str[l]] == 15 ||M[str[l]] == 17
				 ||M[str[l]] == 21)
				{
				//	printf("!!!\n");
					l++;r--;
				}
				else
				{
				//	printf("~~~\n");
					flag = 1 ;
					break;
				}
			}
			else
			{
				if(M.count(str[l]) == 0 || M.count(str[r]) == 0)
				{
					flag = 1;
					break;
				}
				else if(M[str[l]] == -M[str[r]] || M[str[l]] == 1 || M[str[l]] == 7|| M[str[l]] == 8 || M[str[l]] == 3 || M[str[l]] == 4 || M[str[l]] == 10 || M[str[l]] == 11
				 || M[str[l]] == 12 || M[str[l]] == 13 || M[str[l]] == 14 || M[str[l]] == 15 || M[str[l]] == 17 || M[str[l]] == 21)
				{
				//	printf("~~~~\n");
					l++;r--;
				}
				else
				{
					flag = 1;
					break;
				}
			}
		
		}
	//	printf("flag = %d\n" , flag);
		int qq = 0;
		int y = 0 , u = len-1;
		while(y < u)
		{
			
			if(str[y] == str[u])
			{
			//	printf("!!!!\n");
				y++;u--;
			}
			else
			{
				qq = 1;
				break;
			}
		}
	//	printf("qq = %d\n" , qq);
		if(flag == 0 && qq == 0)
		{
			cout << str;
			printf(" -- is a mirrored palindrome.\n\n");
		}
		if(flag == 1 && qq == 0)
		{
			cout << str;
			printf(" -- is a regular palindrome.\n\n");
		}
		if(flag == 0 && qq == 1)
		{
			cout << str;
			printf(" -- is a mirrored string.\n\n");
		}
		if(flag == 1 && qq == 1)
		{
			cout << str;
			printf(" -- is not a palindrome.\n\n");
		}
	}

	return 0;
}
