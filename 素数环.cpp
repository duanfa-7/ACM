#include <iostream>
using namespace std;
bool fun(int sum);//�ж�ǰ������Ƿ�Ϊ���� 
int data[30];//������������
int book[30];//�����ʹ�ù�����
void dfs(int step);//���ѵݹ�
int Recount=0;//data������ܴ漸���� 
int main ()
{
	for (int i = 0;i <30;i++)
	{
		data[i]=i;
	} 
	int m,number=1;
	while(cin>>m&&m!=0)
	{
		if(m%2==0||m==1)//&&fun(data[m]+1)?
		{
			Recount=m;
			cout<<"Case"<<number<<":"<<endl;
			dfs(1);
		}
		else
		{
			cout<<"Case"<<number<<":"<<endl;
			cout<<"No Answer!"<<endl;
		}
		number++;
	}
	return 0;
 } 
 void dfs(int step)
 {
 	if(step==Recount&&fun(data[step]+1))
 	{
 		for(int i=1;i<=Recount;i++)
 	
 			cout<<data[i]<<" ";
 			cout<<endl;
		
 			return;
	}
	 else
	 {
	 	for(int i=2;i<=Recount;i++)
	 	{
	 		if(book[i]==0&&fun(data[step]+i))
	 		{
	 			book[i]=1;
	 			data[step+1]=i;
	 			dfs(step+1);
	 			book[i]=0;
			 }
	 		
		}
	 return;
	 }
 }
 bool fun(int sum)
 {
 	if(sum==0||sum==1)
 	{
 		return false;
	 }
	 else
	 {
	 	for(int i=2;i<sum;i++)
	 	{
	 		if(sum%i==0)
	 		{
	 			return false;
			 }
		 }
		 	 return true;
	 }
  } 
  

