#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x , y , z , ans , t;
	freopen("C:\\Users\\lenovo\\Desktop\\input.txt","w",stdout);
	//cin >> t;
	srand((unsigned)time(NULL));
	t = 100;
	while(t--)
	{
		 
		//cin >> x >> y >> z;
		for(int i = 1 ; i <= 5 ; i ++) //x
		{
			for(int j = 1; j <= 2 * i; j++ )
			{
				if(2 * i > 10) break;
				if(i + j < 3 ) continue;
				cout<< i <<" " << j << " " << rand() % 1000 + 1 << endl;
			}
		}
		//int ret = (x + y) / 3;
		//ans = (x - ret) * z / ret;
		//cout << ans << endl;
	}
	return 0;
 } 
