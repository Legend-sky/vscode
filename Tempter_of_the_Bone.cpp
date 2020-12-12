/*
 * @Author: Whx
 * @Date: 2020-11-25 16:01:20
 * @LastEditTime: 2020-11-25 16:35:39
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, t, sx, sy, ex, ey;
bool f;
int dir[4][2] = {0, -1, -1, 0, 0, 1, 1, 0};
int vis[10][10];
char maze[10][10];
void dfs(int x, int y, int time)
{
    if (f)
        return;
    if (time > t || (time == t && (x != ex || y != ey)))
        return;
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;
    if (t - time < (abs(ex - x) + abs(ey - y)))
        return;
    if ((t - time) % 2 != (abs(ex - x) + abs(ey - y)) % 2)
        return;
    if (x == ex && y == ey && time == t)
    {
        f = true;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (!vis[nx][ny])
        {
            vis[x][y] = 1;
            dfs(nx, ny, time + 1);
            vis[nx][ny] = 0;
        }
    }
    return;
}
int main()
{
    while (cin >> n >> m >> t)
    {
        if (n == 0 && m == 0 && t == 0)
            break;
        f = false;
        memset(vis, 0, sizeof(vis));
        memset(maze, '\0', sizeof(maze));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> maze[i][j];
                if (maze[i][j] == 'S')
                    sx = i, sy = j, vis[i][j] = 1;
                if (maze[i][j] == 'D')
                    ex = i, ey = j;
                if (maze[i][j] == 'X')
                    vis[i][j] = 1;
            }
        }
        dfs(sx, sy, 0);
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}