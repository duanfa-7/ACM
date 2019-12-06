#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const int INF = 0x3f3f3f3f;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int n, m, fire[MAXN][MAXN], people[MAXN][MAXN];
char MAP[MAXN][MAXN];
bool vis[MAXN][MAXN];
struct Node
{
	int x, y, step;
	//Node(){ x=0, y=0;}
	Node(int x, int y, int step): x(x), y(y), step(step) {}
};
queue<Node> Q;
int BFS(int sx, int sy, int op)//坐标 以及 op == 1 表示人走 ， op == 0 表示 火走 
{
	memset(vis, 0, sizeof(vis));
	if (op == 1) //人走 
	{
		people[sx][sy] = 0, vis[sx][sy] = true;
		Q.push(Node(sx, sy, 0));
	}
	while (!Q.empty())
	{
		Node u = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = u.x+dx[i], yy = u.y+dy[i], step = u.step+1;
			if ((xx < 0 || yy < 0 || xx >= n || yy >= m) && op == 1) return step;
			if (xx >= 0 && yy >= 0 && xx < n && yy < m && MAP[xx][yy] != '#' && !vis[xx][yy])
			{
				if (op == 1 && fire[xx][yy] <= step) continue;
				vis[xx][yy] = true;
				if (op == 0) fire[xx][yy] = step;
				if (op == 1) people[xx][yy] = step;
				Q.push(Node(xx, yy, step));
			}
		}
	}
	return -1;
}
int main()
{
	//freopen("C:\\Users\\lenovo\\Desktop\\IN.txt", "r", stdin);
	//freopen("C:\\Users\\lenovo\\Desktop\\OUT.txt", "w", stdout);
	int T; scanf("%d", &T);
	while (T--)
	{
		memset(fire, INF, sizeof(fire));
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%s", MAP[i]);
		int sx, sy;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (MAP[i][j] == 'F') fire[i][j] = 0, vis[i][j] = true, Q.push(Node(i, j, 0));
				if (MAP[i][j] == 'J') sx = i, sy = j;
			}
		}
		BFS(-1, -1, 0);
		while (!Q.empty()) Q.pop();
		int ans = BFS(sx, sy, 1);
		while (!Q.empty()) Q.pop();
		if (ans == -1) printf("IMPOSSIBLE\n");
		else printf("%d\n", ans);
	}
	return 0;
}
/*
2
4 4
####
#JF#
#..#
#..#
3 3
###
#J.
#.F
*/
