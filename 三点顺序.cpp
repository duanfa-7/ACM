#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int x1 , y1 , x2 , y2 , x3 , y3;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
	{
		if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && x3 == 0 && y3 == 0)
		{
			break;
		}
		int A = x2 - x1;
		int B = y2 - y1;
		int C = x3 - x1;
		int D = y3 - y1;
		if(A*D - B*C > 0)
		{
			cout << "1" << endl;
		}
		else
		{
			cout << "0" << endl;
		}
	}
	return 0;
 } 
