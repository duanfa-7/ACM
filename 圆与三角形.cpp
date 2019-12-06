#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int T;
	double xc , yc , r;
//	int x1 , y1 , x2 , y2 ,x3 , y3;
int x[4] , y[4];
double  ans ;
	cin >> T;
	while(T--)
	{
	int flag = 0;
		int min = 9999999 , max = -99999999;
		cin >> xc >> yc >> r;
		int x1 , y1 , x2 , y2 , x3 , y3 , c1 =0, c2=0 ,c3=0, d1 , d2 , d3;
		for(int i = 0  ; i < 3 ; i++)
		{
			cin >> x[i] >> y[i];
			
			ans = sqrt((x[i] - xc) * (x[i] - xc) + (y[i] - yc)*(y[i]-yc));
			if(min > ans)
			{
				min = ans;
			}
			else if(max < ans)
			{
				max = ans;
			}
		}
		
		x1 = x[0];
		y1 = y[0];
		x2 = x[1];
		y2 = y[1];
		x3 = x[2];
		y3 = y[2];
		if(x1 != 0 && x2 != 0 && x3 != 0)
		{
		c1 = y1 - (y1-y2)/(x1-x2)*x1;
		c2 = y2 -(y2-y3)/(x2-x3)*x2;
		c3 = y3 - (y3-y1)/(x3-x1)*x3;
		d1 =abs(yc- ((y1-y2)/(x1-x2)) * xc-c1)/(sqrt(1+(y1-y2)/(x1-x2)));
		d2 =abs(yc-((y2-y3)/(x2-x3))*xc-c2)/(sqrt(1 + (y2-y3)/(x2-x3)));
		d3 = abs(yc - ((y3-y1)/(x3-x1))*xc - c3)/(sqrt(1+(y3-y1)/(x3-x1))); 
		}
	//	printf("d1 = %d d2 =%dd3 =  %d c4 =%d" , d1 , d2 , d3 , c3);
		if(d1 <= ans || d2 <= ans||d3 <= ans)
		{
			flag = 1;
		}
		if(min <= r && max >= r)
		{
			cout <<"Yes" << endl;
		}
		else if(min >r&& max > r)
		{
			if(flag == 1)
			{
				cout <<"Yes" << endl;
			}
			else
			{
				cout << "No"<< endl;
			}
		}
		else
		{
			cout << "No"<< endl;
		}
//		cin >>x1 >>y1;
//		cin >> x2 >> y2 ;
//		cin >> x3 >> y3;
//		
		
	}
	return 0;
}
