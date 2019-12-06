# include <stdio.h>
# include <conio.h>
# include <stdlib.h>

int pre[20][20];									//记录路径数组
int map[20][20];									//存放各景点间的距离

void list( )										//主菜单
{
	system("cls");
	printf("\n\n");
	printf("\t\t          欢迎使用南阳路理工学院导游系统      \n");
	printf("\t\t --------------------------------------------\n");
	printf("\t\t|                                            |\n");
	printf("\t\t|               O(∩_∩)O~~                  |\n");
	printf("\t\t|                                            |\n");
	printf("\t\t|        1.显示校园平面图.                   |\n");
	printf("\t\t|        2.校门口到各个场所的最短路径.       |\n");               
	printf("\t\t|        3.退出                              |\n");
	printf("\t\t|                                            |\n");
	printf("\t\t|                                            |\n");
	printf("\t\t|                                            |\n");
	printf("\t\t --------------------------------------------\n");
	printf("\n\t\t       请输入您要进行的操作的序号          \n");
}

void view( )							      //浏览校园地图
{
	system("cls");
	printf("\t                    南阳路理工学院新校区                  \n");
	printf("\t ---------------------------------------------------------\n");
	printf("\t|       |       10      |     	 ‖ 6  汇森楼  |       |\n");
	printf("\t|       |   图书馆      |  		 ‖------------        |\n");
	printf("\t|        ---------------   		 ‖                    |\n");
	printf("\t|                ---------------   ‖--------------------|\n");
	printf("\t|               |               |  ‖  ------      ------|\n");
	printf("\t|=========      |        5      |  ‖ |   仲 |    | 教   |\n");
	printf("\t|        ‖     |    齐贤园     |  ‖ |7 景  |    |8学   |\n");
	printf("\t|4 公寓  ‖     |               |  ‖ |    园|    | 楼   |\n");
	printf("\t|        ‖     |               |  ‖ |      |    | 2    |\n");
	printf("\t=========  ==============================================|\n");
	printf("\t|------- ‖ ‖                  ‖               ‖  3   |\n");
	printf("\t|     1 |‖ ‖  操场  |﹨       ‖               ‖南门  |\n");
	printf("\t|    教 |‖ ‖        |  ﹨     ‖               ‖      |\n");
	printf("\t| 9  学 |‖ ‖        |-----    ‖    --------   ‖------|\n");     
	printf("\t|    楼 |‖ ‖        |         ‖   |2文法学院| ‖      |\n");   
	printf("\t|========================================================|\n");
	printf("\t|                                       --------------   |\n");
	printf("\t|                                      |              |  |\n");
	printf("\t|                                      |    1 校门    |  |\n");    
	printf("\t --------------------------------------------------------\n");
	printf("\n\t                按任意键返回主菜单.                    \n");
	getch();
	list();
}

void floyd( )					  			//弗洛伊德算法求最短路径 
{                                          
    int i,j,k;     
    for(k = 1;k <= 10;k ++)//引入第三个点   松弛操作 
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

void judge(int key)								    //判断景点序号
{
	switch(key)
	{
		case  1  :printf("校门 ");return;
		case  2  :printf("文法学院");return;
		case  3  :printf("南门");return;
		case  4  :printf(" 公寓");return;
		case  5  :printf("仲景园");return;
		case  6  :printf("汇森楼 ");return;
		case  7  :printf("齐贤园 ");return;
		case  8  :printf("教学楼2 ");return;
		case  9  :printf("教学楼1");return;
		case  10 :printf("图书馆");return ; 
		default  :printf("ERROR ");return;
	}
}
int ans ;
void path(int x,int y)							//输出起点到终点的路径
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
         x = pre[x][y];			//把现在的节点赋值下一次的初始节点 
     }
	 printf("--> ");
     judge(y);
     int ww = pre[x][y];
    // printf("ww = %d , x = %d" , ww , x);
   //printf("pre[%d][%d] = %d  " , x , y , pre[x][y]);
	 printf("\n");
	 ans += map[ww][x];
//	 printf("map[x][y] = %d" , map[pre[x][y]][y]);
	 printf("最短距离为：%d" , ans);
	 ans = 0 ;
}
void Initiate( )								//初始化map[]和pre[]，存放map[]的距离,权值 
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

void find( )									//进行查找起点到终点操作
{
	floyd();
	system("cls");
	int strat,end;
    printf("请选择起点的景点(1-10): ");
	scanf("%d",&strat);
	printf("\n");
	printf("请选择终点的景点(1-10): ");
	scanf("%d",&end);
	printf("\n");
	if(strat != end)
    {	 
		 path(strat,end);
 		 printf("\n");
	}
	else 	
	{
	 	printf("起点与终点相同.\n");
	}
	printf("按任意键返回.\n");
	getch();
}

void door( )
{
	system("cls");
	int i;
	printf("校门口各地方的最短路径.\n\n");
	for(i = 2;i <= 10;i ++)
	{
		path(1,i);     //  1代表大门口，i代表其他的结点 
		printf("\n");
	}
	printf("按任意键返回.\n");
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

