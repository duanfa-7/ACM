#include <bits/stdc++.h>
#include <conio.h>
#include <stdlib.h> 
#include <windows.h>
using namespace std;
#define INF 0x3f3f3f3f
int Map[1500][1500];
int dis[2200],vis[2200];
int pre[2200];
map<int , string >V;
int t,n,a,b,c,s,e;
void init()
{
	int a , b , c ;
	char ch[4]; 
	string str;
	memset(pre , -1 , sizeof(pre));
	memset(Map , INF , sizeof(Map)); 
	V[1] = "���� ";
	V[2] = "���͹㳡"; 
	V[3] = "����԰ ";
	V[4] =  "15�� ";
	V[5] = "ͼ��� "; 
	V[6] = "������ ";
	V[7] = "��ɭ¥ "; 
	V[8] = "ʳ��  ";
	V[9] = "������վ";
	V[10] = "���깫Ԣ"; 
	Map[1][2] = Map[2][1] = 3;
	Map[1][3] = Map[3][1] = 2;
	Map[2][3] = Map[3][2] = 5;
	Map[3][4] = Map[4][3] = 6;
	Map[3][6] = Map[6][3] = 3;
	Map[4][5] = Map[5][4] = 7;
	Map[5][6] = Map[6][5] = 1;
	Map[4][7] = Map[7][4] = 11;
	Map[1][8] = Map[8][1] = 5;
	Map[5][9] = Map[9][5] = 12;
	Map[6][10] = Map[10][6] = 4;
	Map[8][10] = Map[10][8] = 9;
}
void dijkstra(int s)
{
	n=10; 
	for(int i=1;i<=n;i++)
	{
		dis[i] = Map[s][i];
		vis[i] = 0;
		pre[i] = -1;
	}
	vis[s] = 1; 
	int min=INF,u;
	for(int i=1;i<=n;i++)
	{
		min=INF;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&dis[j]<min)
			{
				min=dis[j];
				u=j;
			}
		}
		vis[u]=1;
		for(int v=1;v<=n;v++)
		{
			if(!vis[v]&&dis[v]>dis[u]+Map[u][v])
			{
				dis[v]=dis[u]+Map[u][v];
				pre[v] = u;
			}
		}
	}
}
void print(int v)
{
	if(pre[v] == -1)
	{
	cout<< V[v];
		return ;
	}
	print(pre[v]);
cout <<"--->"<<V[v];
}
void showsig()
{
	system("cls");
	puts("\n\n\n\n\n");
	printf("\t\t\t\t          ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~     \n");
	printf("\t\t\t\t                ��ӭ���� У԰����         \n");													
	printf("\t\t\t\t          ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~     \n");
	puts("\n\n\n\t\t\t\t\t-------------------------------");
	for(int i = 1 ; i <= 10 ; i++)
	{
		cout<<"\t\t\t\t\t~~~~~~~~~~~"<<i<<"."<<V[i]<<"~~~~~~~~~~~~"<<endl;;
	}
	puts("\t\t\t\t\t-------------------------------");
}
void sig()
{
	puts("\n\n\n\n\n");
	printf("\t\t\t\t          ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~    \n");
	printf("\t\t\t\t                ��ӭ���� У԰����        \n");													
	printf("\t\t\t\t          ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~    \n");
	puts("\n\n\n\t\t\t\t-------------------------------");
	showsig();
	int a;
	puts("\n\n\n\t\t\t\t����Ҫ��ѯ�ľ�����Ϣ(��'0'�˳�)");
	while(cin>>a)
	{
		if(a == 0) break;
		if(a == 1) cout<<V[1]<<"������ѧԺ�Ĵ���ׯ������"<<endl;
		if(a == 2) cout<<V[2]<<"�����л,�ݳ��ĵط�~"<<endl; 
		if(a == 3) cout<<V[3]<<"ѧ�������Ͼ��������ﳿ��,����~"<<endl; 
		if(a == 4) cout<<V[4]<<"���ѧԺѧ���ǵ���Ҫ��ѧ¥"<<endl;
		if(a == 5) cout<<V[5]<<"���д��,��ѧϰ��ѧ���ǳ����ۼ��ĵط�~"<<endl;
		if(a == 6) cout<<V[6]<<"ϲ���˶���ѧ���ǳ������˴�����,��ë��ȵ�~"<<endl;
		if(a == 7) cout<<V[7]<<"������Ĵ�ѧ�����˴�ҵ"<<endl;
		if(a == 8) cout<<V[8]<<"ѧУ��ʳ��,��������~"<<endl;
		if(a == 9) cout<<V[9]<<"����,�İ����ĵط�"<<endl;
		if(a == 10) cout<<V[10]<<"����������ѧ��ס��¥"<<endl;   
		
	}
}
int show()
{
	system("color 70");
	puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t____________________У԰����\n");
		puts("\t\t\t\t\t\t\t\t\t\t\t\t_____design by:�����");
}
int show1()
{
		
		system("PAUSE");
		system("cls"); 
			puts("\n\n\n\n\n");
			printf("\t\t\t\t          ������������������������������������������������������������\n");
			printf("\t\t\t\t         |                    ��ӭ���� У԰����                      |\n");													
			printf("\t\t\t\t         |~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~|\n");
			printf("\t\t\t\t         |                          	                             |\n");
			printf("\t\t\t\t         | 	 	1- ������ѧԺ���������Ƽ�������Ϣ          |\n");
			printf("\t\t\t\t         |                                                           |\n");
			printf("\t\t\t\t         |              2 - ���·���������ѯ                       |\n");
			printf("\t\t\t\t         |                     	                                     |\n");
			printf("\t\t\t\t         |              3-�˳�                                       |\n");
			printf("\t\t\t\t         |                                                           |\n");
			printf("\t\t\t\t         |                                                           |\n");
			printf("\t\t\t\t         ������������������������������������������������������������|\n");
		
}
void disshow()
{
		system("cls");
		puts("\n\n\n\n\n");
		printf("\t\t\t\t         ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~          \n");
		printf("\t\t\t\t                 ��ӭ���� У԰����                    \n");													
		printf("\t\t\t\t         ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~          \n");
		printf("\t\t\t\t        |          1- ���򵼺�             |          \n");
		printf("\t\t\t\t        |                                  |          \n");
		printf("\t\t\t\t        |          2-�����򵼺�            |          \n");
		printf("\t\t\t\t        |                                  |          \n");
		printf("\t\t\t\t        |          3-�˳�                  |          \n");
		printf("\t\t\t\t        |                                  |          \n");
		int a,b,c;
		puts("\t\t\t\t");
		while(cin>>a)
		{
			if(a == 1)
			{
				
				showsig();
				printf("\t\t\t\t         ���������������ڵĵص�");cin>>b;
				printf("\t\t\t\t         ������������Ҫȥ�ĵص�");cin>>c;
				dijkstra(b);
				cout<<"\t\t\t\t"<<"��"<<V[b]<<"��"<<V[c]<<"����̾�����:"<<dis[c]<<endl;
				printf("\t\t\t\t·������:\n"); 
				printf("\t\t\t\t"); 
				cout<<V[b]<<"---->";
				print(c);	
			}
			if(a == 2)
			{
				showsig();
				printf("\t\t\t\t         �����������ڵĵص�");cin>>b;
				dijkstra(b);
				for(int i = 1 ; i <= 10 ; i++)
				{
					if(i == b) continue;
					cout<<"\t\t\t\t��"<<V[b]<<"��"<<V[i]<<"����̾�����"<<dis[i]<<endl;
				}
			}
			if(a == 3) break;
			printf("\n"); 
			system("PAUSE");
			system("cls");
		printf("\t\t\t\t         ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~          \n");
		printf("\t\t\t\t                 ��ӭ���� У԰����                    \n");													
		printf("\t\t\t\t         ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~          \n");
		printf("\t\t\t\t        |          1- ���򵼺�             |          \n");
		printf("\t\t\t\t        |                                  |          \n");
		printf("\t\t\t\t        |          2-�����򵼺�            |          \n");
		printf("\t\t\t\t        |                                  |          \n");
		printf("\t\t\t\t        |          3-�˳�                  |          \n");
		printf("\t\t\t\t        |                                  |          \n");
		puts("\t\t\t\t");
		}
		
}

void p()
{
	show();
	show1();
	int a;
	printf("\t\t\t\t");
	printf("�������ѯѡ�"); 
	while(cin>>a)
	{
		if(a == 1) sig();
		if(a == 2) disshow();
		if(a == 3) break;
		puts("\t\t\t\t");
		show1(); 
	}	 	
}
int main()
{
	init();
	p();
	return 0;
}
