#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int maxn = 2e3+30;
int Qx , Qy;
struct node
{
	int x;
	int y;
}op[maxn];
double count1(int x , int y)
{
	double ans = sqrt((x-Qx)*(x-Qx) + (y-Qy)*(y-Qy));
	return ans;
}
double count3(int x1 , int y1 , int x2 , int y2)
{
	double ans = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	return ans;
}
double count2(double a , double b , double c)
{
	double ans;
	ans = acos(a*a +b*b-c*c/(2*b*a));
	return PI-ans;
}
int main()
{
	int t , n;
	scanf("%d" , &t);
	for(int k = 1 ; k <= t ; k++)
	{
		double ans = 0;
		scanf("%d" , &n);
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%d %d" , &op[i].x , &op[i].y);
		}
		scanf("%d %d" , &Qx , &Qy);
		for(int i = 0 ; i < n ; i++)
		{
			//double a = count3(op[(i+1)%(n)].x ,op[(i+1)%(n)].y , op[(i-1+n)%(n+1)].x ,op[(i-1+n)%(n+1)].y);
			//double b = count3(op[i%(n+1)].x , op[i%(n+1)].y , op[(i+1)%(n+1)].x ,op[(i+1)%(n+1)].y);
			//double c = count3(op[i%(n+1)].x , op[i%(n+1)].y , op[(i-1+n)%(n+1)].x ,op[(i-1+n)%(n+1)].y);
      double a = count3(op[i].x,op[i].y,op[(i+1)%n].x,op[(i+1)%n].y);
      double b = count3(op[(i+1)%n].x,op[(i+1)%n].y,op[(i+2)%n].x,op[(i+2)%n].y);
      double c = count3(op[i].x,op[i].y,op[(i+2)%n].x,op[(i+2)%n].y);
      //cout<<a<<"  " << b << " " << c<<endl;
		//	printf("count2(%f , %f , %f) = %.3f\n" , a , b , c , count2(a , b , c));
      double d = PI-acos((a*a+b*b-c*c)/(2*a*b));
      double e = count1(op[(i+1)%n].x,op[(i+1)%n].y);
      //cout<<d <<"  " << e <<endl;
      ans += d*e;
			//ans += (count1(op[(i+1)%n].x,op[(i+1)%n].y) * (PI-acos((a*a+b*b-c*c)/(2*a*b))));
		}
		printf("Case #%d: %.3f\n" , k , ans);
	}
	return 0;
 } 
