#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{
	char ch[50][50] , wq[50][50];
	int n, m , T;
	scanf("%d" , &T);
	while(T--)
	{
		string s;
		int ans = 0 ;
		int a = 0 , b = -1;
		scanf("%d %d" , &n , &m);
		for(int i = 0 ; i < n ; i++)
		{
			b++;
			for(int j = 0 ; j < m ; j++)
			{
				cin >> ch[i][j];
				wq[a][b] = ch[i][j];
				a++;
			}
			a = 0;
		}
		cin >> s;
		for(int i = 0 ; i < s.length() ; i++)
		{
			if(s[i] == 'L')
			{
				ans--;
			}
			else if(s[i] == 'R')
			{
				ans++;
			}
		}
		if(ans < 0)
		{
			ans+=400; 
			ans = ans %4;
			
		}
		else
		{
			ans = ans%4;
		}
ans = ans + '0';
//	printf("ans = %c\n" , ans);
//cin >> ans;
//ans += '0';
			switch(ans)
			{
				case '0':
					printf("%d %d\n" , n , m);
					for(int i = 0 ; i < n ; i++)
					{
						for(int j = 0 ; j < m ; j++)
						{
						cout << ch[i][j];
						}
						cout << endl;
					}
					break;
						case '1':
							printf("%d %d\n" , m , n);
				for(int i = 0 ; i < m; i++)
				{
					for(int j = n-1 ; j >= 0; j--)
					{
							if(wq[i][j] == '|')
							{
								wq[i][j] = '-';
							}
							else if(wq[i][j] == '-')
							{
								wq[i][j] = '|';
							}
							cout << wq[i][j];
					}
					cout << endl;
				}
				break;
					case '2':
						printf("%d %d\n" , n , m);
					for(int i = n-1 ; i >= 0 ; i--)
					{
						for(int j = m - 1 ; j >= 0; j--)
						{
	//						if(ch[i][j] == '|')
	//						{
	//							ch[i][j] = '-';
	//						}
	//						else if(ch[i][j] == '-')
	//						{
	//							ch[i][j] = '|';
	//						}
						cout << ch[i][j];
						}
						cout << endl;
					}
					break;
					case '3':
						printf("%d %d\n" , m , n);
				for(int i = m-1 ; i >= 0; i--)
				{
					for(int j = 0 ; j < n; j++)
					{
							if(wq[i][j] == '|')
							{
								wq[i][j] = '-';
							}
							else if(wq[i][j] == '-')
							{
								wq[i][j] = '|';
							}
							cout << wq[i][j];
					}
					cout << endl;
				}
			}
	cout << endl;		
	}
	return 0 ;
}
