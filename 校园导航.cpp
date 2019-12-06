# include <stdio.h>
# include <conio.h>
# include <stdlib.h>

int pre[20][20];									//��¼·������
int map[20][20];									//��Ÿ������ľ���

void list( )										//���˵�
{
	system("cls");
	printf("\n\n");
	printf("\t\t          ��ӭʹ������·��ѧԺ����ϵͳ      \n");
	printf("\t\t --------------------------------------------\n");
	printf("\t\t|                                            |\n");
	printf("\t\t|               O(��_��)O~~                  |\n");
	printf("\t\t|                                            |\n");
	printf("\t\t|        1.��ʾУ԰ƽ��ͼ.                   |\n");
	printf("\t\t|        2.У�ſڵ��������������·��.       |\n");               
	printf("\t\t|        3.�˳�                              |\n");
	printf("\t\t|                                            |\n");
	printf("\t\t|                                            |\n");
	printf("\t\t|                                            |\n");
	printf("\t\t --------------------------------------------\n");
	printf("\n\t\t       ��������Ҫ���еĲ��������          \n");
}

void view( )							      //���У԰��ͼ
{
	system("cls");
	printf("\t                    ����·��ѧԺ��У��                  \n");
	printf("\t ---------------------------------------------------------\n");
	printf("\t|       |       10      |     	 �� 6  ��ɭ¥  |       |\n");
	printf("\t|       |   ͼ���      |  		 ��------------        |\n");
	printf("\t|        ---------------   		 ��                    |\n");
	printf("\t|                ---------------   ��--------------------|\n");
	printf("\t|               |               |  ��  ------      ------|\n");
	printf("\t|=========      |        5      |  �� |   �� |    | ��   |\n");
	printf("\t|        ��     |    ����԰     |  �� |7 ��  |    |8ѧ   |\n");
	printf("\t|4 ��Ԣ  ��     |               |  �� |    ԰|    | ¥   |\n");
	printf("\t|        ��     |               |  �� |      |    | 2    |\n");
	printf("\t=========  ==============================================|\n");
	printf("\t|------- �� ��                  ��               ��  3   |\n");
	printf("\t|     1 |�� ��  �ٳ�  |��       ��               ������  |\n");
	printf("\t|    �� |�� ��        |  ��     ��               ��      |\n");
	printf("\t| 9  ѧ |�� ��        |-----    ��    --------   ��------|\n");     
	printf("\t|    ¥ |�� ��        |         ��   |2�ķ�ѧԺ| ��      |\n");   
	printf("\t|========================================================|\n");
	printf("\t|                                       --------------   |\n");
	printf("\t|                                      |              |  |\n");
	printf("\t|                                      |    1 У��    |  |\n");    
	printf("\t --------------------------------------------------------\n");
	printf("\n\t                ��������������˵�.                    \n");
	getch();
	list();
}

void floyd( )					  			//���������㷨�����·�� 
{                                          
    int i,j,k;     
    for(k = 1;k <= 10;k ++)//�����������   �ɳڲ��� 
    {
        for(i = 1;i <= 10;i ++)
        {
            if( i == k || map[i][k]== -1 ) continue;    
            for(j = 1;j <= 10;j ++)
            {
                if( k == j || i == j || map[k][j] == -1 ) continue;  
                int tmp = map[i][k] + map[k][j];     
                if(map[i][j] == -1 || map[i][j] > tmp) 
                {
                    map[i][j] = tmp;       
                    pre[i][j] = pre[i][k]; 
                }
                else if(map[i][j] == tmp && pre[i][k] < pre[i][j])
                {
                    pre[i][j]=pre[i][k];
                }
            }
        }
    }
}

void judge(int key)								    //�жϾ������
{
	switch(key)
	{
		case  1  :printf("У�� ");return;
		case  2  :printf("�ķ�ѧԺ");return;
		case  3  :printf("����");return;
		case  4  :printf(" ��Ԣ");return;
		case  5  :printf("�پ�԰");return;
		case  6  :printf("��ɭ¥ ");return;
		case  7  :printf("����԰ ");return;
		case  8  :printf("��ѧ¥2 ");return;
		case  9  :printf("��ѧ¥1");return;
		case  10 :printf("ͼ���");return ; 
		default  :printf("ERROR ");return;
	}
}
int ans ;
void path(int x,int y)							//�����㵽�յ��·��
{
	floyd();
 	 printf("Path:");
	 judge(x);
     while(pre[x][y] != y)
     {
     //	printf("pre[%d][%d] = %d  " , x , y , pre[x][y]);
    	ans += map[x][pre[x][y]];
		 printf("--> ");
         judge(pre[x][y]);
         x = pre[x][y];			//�����ڵĽڵ㸳ֵ��һ�εĳ�ʼ�ڵ� 
     }
	 printf("--> ");
     judge(y);
     int ww = pre[x][y];
    // printf("ww = %d , x = %d" , ww , x);
   //printf("pre[%d][%d] = %d  " , x , y , pre[x][y]);
	 printf("\n");
	 ans += map[ww][x];
//	 printf("map[x][y] = %d" , map[pre[x][y]][y]);
	 printf("��̾���Ϊ��%d" , ans);
	 ans = 0 ;
}
void Initiate( )								//��ʼ��map[]��pre[]�����map[]�ľ���,Ȩֵ 
{
	int i,j;
	for(i = 1;i <= 10;i ++)
	{
		for(j = 1;j <= 10;j ++)
		{
			pre[i][j] = j;   
			if(i ==j)map[i][j] = 0;
			else
				map[i][j] = -1;
		}
	}
	map[1][2] = map[2][1] = 50;
	map[1][3] = map[3][1] = 30;
	map[2][7] = map[7][2] = 200;
	map[3][4] = map[4][3] = 500;
	map[3][5] = map[5][3] = 500;
	map[4][5] = map[5][4] = 100;
	map[5][6] = map[6][5] = 150;
	map[5][7] = map[7][5] = 70;
	map[5][10]= map[10][5]= 50;
	map[6][7] = map[7][6] = 80;
	map[6][10]= map[10][6]= 130;
	map[7][8] = map[8][7] = 100;
	map[7][9] = map[9][7] = 300;
	map[7][10]= map[10][7]= 230;
}

void find( )									//���в�����㵽�յ����
{
	floyd();
	system("cls");
	int strat,end;
    printf("��ѡ�����ľ���(1-10): ");
	scanf("%d",&strat);
	printf("\n");
	printf("��ѡ���յ�ľ���(1-10): ");
	scanf("%d",&end);
	printf("\n");
	if(strat != end)
    {	 
		 path(strat,end);
 		 printf("\n");
	}
	else 	
	{
	 	printf("������յ���ͬ.\n");
	}
	printf("�����������.\n");
	getch();
}

void door( )
{
	system("cls");
	int i;
	printf("У�ſڸ��ط������·��.\n\n");
	for(i = 2;i <= 10;i ++)
	{
		path(1,i);     //  1������ſڣ�i���������Ľ�� 
		printf("\n");
	}
	printf("�����������.\n");
	getch();
}

int main( )
{
	bool flag = false;
	while( !flag )
	{
		list();
		char s[3];
		scanf("%s",s);
		Initiate();           
		switch(s[0])
		{
			case '1' :  view();break;	 
			case '2' :  find();break;
			case '3' :  flag = true; break;
			default  :  list();break;
		}
	}
	return 0;
}

