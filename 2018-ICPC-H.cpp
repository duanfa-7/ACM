/*
1.存下攻击每个怪兽需要的次数
2.从小到大排列  武力值/次数 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5+8; 
struct node
{
	int v , w , time;
}a[maxn];
bool cmp(node a , node b)
{
	return a.time * b.w > a.w * b.time; 
}
int main()
{
	int t , n;
	scanf("%d" , &t);
	for(int k = 1 ; k <= t ; k++)
	{
		scanf("%d" , &n);
		ll tot = 0;
		for(int j = 1 ; j <= n ; j++)
		{
			scanf("%d %d" , &a[j].v , &a[j].w);
			tot += a[j].w;
			int l = 1;
			a[j].time = 0;
			while(a[j].v > 0)
			{
				a[j].time++;//a[j].time = l;
				a[j].v -= l;
				l++;
			}
		}
		sort(a+1 , a+n+1 , cmp);
		ll sum = 0;//求和
		for(int i = n ; i >= 1 ; i--)
		{
			sum += a[i].time * tot;
			tot -= a[i].w;
		}
		printf("Case #%d: %lld\n" , k , sum);
	}
	return 0;
} 