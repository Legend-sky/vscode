/*
 * @Author: Whx
 * @Date: 2020-11-18 18:36:50
 * @LastEditTime: 2020-11-21 10:30:02
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 202;
char mp[maxn][maxn];
bool vis[maxn][maxn];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int sx, sy, ex, ey;
int n, m;
struct Node
{
    int x, y, step;
};
int step[maxn][maxn];
bool operator<(Node a, Node b)
{
    return a.step > b.step;
}
bool ok(int x, int y)
{
    if (x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] != '#')
        return true;
    return false;
}
void bfs()
{
    step[sx][sy] = 0;
    memset(vis, 0, sizeof(vis));
    vis[sx][sy] = 1;
    priority_queue<Node> q;
    Node tp;
    tp.x = sx, tp.y = sy, tp.step = 0;
    q.push(tp);
    while (!q.empty())
    {
        Node first = q.top();
        if (first.x == ex && first.y == ey)
            break;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = first.x + dx[i];
            int ny = first.y + dy[i];
            if (!vis[nx][ny] && ok(nx, ny))
            {
                vis[nx][ny] = 1;
                tp.x = nx;
                tp.y = ny;
                if (mp[nx][ny] == 'x')
                {
                    step[nx][ny] = first.step + 2;
                    tp.step = first.step + 2;
                }
                else
                {
                    step[nx][ny] = first.step + 1;
                    tp.step = first.step + 1;
                }
                q.push(tp);
            }
        }
    }
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> mp[i][j];
                if (mp[i][j] == 'r')
                    sx = i, sy = j;
                else if (mp[i][j] == 'a')
                    ex = i, ey = j;
            }
        bfs();
        if (!vis[ex][ey])
            printf("Poor ANGEL has to stay in the prison all his life.\n");
        else
            printf("%d\n", step[ex][ey]);
    }
    return 0;
}