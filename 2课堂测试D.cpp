/*
 * @Author: Whx
 * @Date: 2021-01-06 19:04:53
 * @LastEditTime: 2021-01-06 19:59:28
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#define ll long long

using namespace std;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;
struct node
{
    int x, y, step = 1000;
} st, en;
int vis[15][15];
char ma[15][15];
int n, m;
int dir[4][2] = {0, -1, -1, 0, 0, 1, 1, 0};
void bfs()
{
    memset(vis, 0, sizeof(vis));
    node tmp, ne, nne;
    vis[st.x][st.y] = 1;
    queue<node> q;
    q.push(st);
    while (!q.empty())
    {
        tmp = q.front();
        if (tmp.x == en.x && tmp.y == en.y)
        {
            en.step = tmp.step;
            return;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            ne.x = tmp.x + dir[i][0];
            ne.y = tmp.y + dir[i][1];
            nne.x = tmp.x + dir[i][0] * 2;
            nne.y = tmp.y + dir[i][1] * 2;
            if (nne.x >= 1 && nne.x <= n && nne.y >= 1 && nne.y <= m && !vis[nne.x][nne.y] && ma[ne.x][ne.y] == '*' && ma[nne.x][nne.y] == '.')
            {
                nne.step = tmp.step + 1;
                vis[nne.x][nne.y] = 1;
                q.push(nne);
            }
            if (ne.x >= 1 && ne.x <= n && ne.y >= 1 && ne.y <= m && !vis[ne.x][ne.y] && ma[ne.x][ne.y] == '.')
            {
                ne.step = tmp.step + 1;
                vis[ne.x][ne.y] = 1;
                q.push(ne);
            }
        }
    }
}
int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> ma[i][j];
            }
        }
        scanf("%d%d%d%d", &st.x, &st.y, &en.x, &en.y);
        st.step = 0;
        en.step = 1000;
        bfs();
        if (en.step == 1000)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", en.step);
        }
    }
    return 0;
}
