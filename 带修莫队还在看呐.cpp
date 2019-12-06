#include <bits/stdc++.h>
 using namespace std;
 const int maxn = 10005;
 int n , m , Q , a[maxn];
 struct Query
 {
 	int ID , l , r , time , ans;
 	Query(){}
 	Query(int _ID , int _l , int _r , int _time)//为什么这里没有ans 
	 {
	 	ID = _ID;
	 	l = _l;
	 	r = _r ;
	 	time = _time;
	 	ans = 0;
	 }
 }q[maxn];
 struct Change
 {
 	int pos , old , New;
 	Change(){}
 	Change(int _pos ,  int _old , int _New )
	 {
	 	pos = _pos;
	 	old = _old;
		New = _New;
	 }
 }c[maxn];
 int block , l , r , T , ans , cnt[maxn*100] , pos[maxn] , now[maxn];
bool cmp(Query a  , Query b)
{
	return pos[a.l] == pos[b.l] ? (pos[a.r] == pos[b.r] ? a.time < b.time : a.r < b.r) : a.l < b.l;	
}
bool cmp_ID(Query a , Query b)
{
	return a.ID < b.ID;
}
void update(int x , int d)
{//在左移右移的过程中要维护ans这个值 ， 他表示的是彩笔的种数
//模拟一下过程就明白了 （想不到） 
	cnt[x] += d;
	if(cnt[x] == 0 && d == -1) ans--;
	if(cnt[x] == 1 && d == 1) ans++;
}
void change(int x , int d)//将x这个位置的值改为d 
{
	if(l <= x && x <= r)//不太清楚为什么要这么写 
	{//这里为什么要用逗号啊 
		update(d , 1),//改了的这个值对ans有没有影响 ， 维护ans 
		update(a[x] , -1);//原先的值去掉以后 ， 对ans的影响 
	}
	a[x] = d;
}
 int main()
 {
 	scanf("%d %d" , &n , &m);getchar();
	 block = pow(n , 2.0 / 3);
	 for(int i = 1 ; i <= n ; i++)
	 {
	 	scanf("%d" , &a[i]);
	 	now[i] = a[i];//记录没有更改前的数 
	 	pos[i] = (i-1)/block+1;
	  } getchar();
	 while(m--)
	 {
	 	printf("000000\n");
	 	char op;
	 	int x , y;
	 	//scanf(" %c %d%d", &op, &x, &y);
	 scanf("%c %d%d" , &op , &x , &y);getchar();
	 	if(op == 'Q')
	 	{//猜测 ： 这里T一直为0 表示他们是同一时间，也就是说，他们是初始就有，没有改变值 
	 //	然后下面++T,T的值就改变了 ，再以此排序就知道更改前后的顺序了 ，比如先查询再更改再查询 ，T就不一样了 
	 		q[Q++] = Query(Q , x , y , T);//分别表示ID号 ，l, r , 时间 
		 }
		 if(op == 'R')
		 {//这边为什么要用++T？ 
		 	c[++T] = Change(x , now[x] , y);//x表示要改的位置的下标 ，
			//  now[x]表示未更改之前的数字 ，y表示 即将替代的数字 
		 	now[x] = y;// 已更改 
		  } 
	  } 
	  sort(q , q+Q , cmp); //为什么时间是第三关键字？
	// 如果按时间来排的话 ， 莫队就没有意义啦~~全程来回来回
	//疑问：要a.l=b.l && a.r = b.r，才会按时间排序？那就是相等的话才有时间上的安排？
	//为什么不是a和b都在一个分块里，然后再这个分块中按时间排序。 
	l = 1, r = 0 , T = 0 , ans = 0;
	for(int i = 0 ; i < Q ; i++)
	{
		while(T < q[i].time)change(c[T].pos , c[++T].New);//当我们要查找的时间大于上一个，要更改值 下面同理 
		while(T > q[i].time)change(c[T--].pos , c[T].old);
		while(l < q[i].l) update(a[l++] , -1);
		while(l > q[i].l) update(a[--l] , 1);
		while(r < q[i].r) update(a[++r] , 1);
		while(r > q[i].r) update(a[r--] , -1);
		q[i].ans = ans; 
	}
	sort(q , q+Q , cmp_ID) ;
	for(int i = 0 ; i < Q ; i++)
	{
		printf("%d\n" , q[i].ans);
	}
 	return 0;
 }
  
