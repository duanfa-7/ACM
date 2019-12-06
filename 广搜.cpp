#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct node
{
    int x,y;
}point;
//struct node point;

char MAP[100][100];
bool book[100][100];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n,m;

bool bfs(int sx, int sy)
{
    book[sx][sy] = 1;
    queue<node> q;
    point.x = sx;
    point.y = sy;
    q.push(point);
    while(!q.empty())
    {
        if((q.front()).x == n-1 && (q.front()).y == m-1)
            return true;
        for(int i = 0; i < 4; i++)
        {
            int tx = (q.front()).x + dir[i][0];
            int ty = (q.front()).y + dir[i][1];
            if(MAP[tx][ty]=='1' && book[tx][ty] == false && tx >= 0 && ty >= 0 && tx < n && ty < m)
            {
                book[tx][ty] = true;
                point.x = tx;
                point.y = ty;
                q.push(point);
            }
        }
        q.pop();
    }
    return false;
}
int main()
{
    memset(MAP,'0',sizeof(MAP));
    memset(book,0,sizeof(book));
    cin>>n>>m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        cin>>MAP[i][j];

    if(bfs(0,0))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}
/**
8 8
11110001
00010001
00011111
11110000
10001111
11111001
00010000
00011111
*/
