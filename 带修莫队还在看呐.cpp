#include <bits/stdc++.h>
 using namespace std;
 const int maxn = 10005;
 int n , m , Q , a[maxn];
 struct Query
 {
 	int ID , l , r , time , ans;
 	Query(){}
 	Query(int _ID , int _l , int _r , int _time)//Ϊʲô����û��ans 
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
{//���������ƵĹ�����Ҫά��ans���ֵ �� ����ʾ���ǲʱʵ�����
//ģ��һ�¹��̾������� ���벻���� 
	cnt[x] += d;
	if(cnt[x] == 0 && d == -1) ans--;
	if(cnt[x] == 1 && d == 1) ans++;
}
void change(int x , int d)//��x���λ�õ�ֵ��Ϊd 
{
	if(l <= x && x <= r)//��̫���ΪʲôҪ��ôд 
	{//����ΪʲôҪ�ö��Ű� 
		update(d , 1),//���˵����ֵ��ans��û��Ӱ�� �� ά��ans 
		update(a[x] , -1);//ԭ�ȵ�ֵȥ���Ժ� �� ��ans��Ӱ�� 
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
	 	now[i] = a[i];//��¼û�и���ǰ���� 
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
	 	{//�²� �� ����TһֱΪ0 ��ʾ������ͬһʱ�䣬Ҳ����˵�������ǳ�ʼ���У�û�иı�ֵ 
	 //	Ȼ������++T,T��ֵ�͸ı��� �����Դ������֪������ǰ���˳���� �������Ȳ�ѯ�ٸ����ٲ�ѯ ��T�Ͳ�һ���� 
	 		q[Q++] = Query(Q , x , y , T);//�ֱ��ʾID�� ��l, r , ʱ�� 
		 }
		 if(op == 'R')
		 {//���ΪʲôҪ��++T�� 
		 	c[++T] = Change(x , now[x] , y);//x��ʾҪ�ĵ�λ�õ��±� ��
			//  now[x]��ʾδ����֮ǰ������ ��y��ʾ ������������� 
		 	now[x] = y;// �Ѹ��� 
		  } 
	  } 
	  sort(q , q+Q , cmp); //Ϊʲôʱ���ǵ����ؼ��֣�
	// �����ʱ�����ŵĻ� �� Ī�Ӿ�û��������~~ȫ����������
	//���ʣ�Ҫa.l=b.l && a.r = b.r���Żᰴʱ�������Ǿ�����ȵĻ�����ʱ���ϵİ��ţ�
	//Ϊʲô����a��b����һ���ֿ��Ȼ��������ֿ��а�ʱ������ 
	l = 1, r = 0 , T = 0 , ans = 0;
	for(int i = 0 ; i < Q ; i++)
	{
		while(T < q[i].time)change(c[T].pos , c[++T].New);//������Ҫ���ҵ�ʱ�������һ����Ҫ����ֵ ����ͬ�� 
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
  
