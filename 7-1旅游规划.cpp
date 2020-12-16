/*
 * @Author: Whx
 * @Date: 2020-12-15 19:04:02
 * @LastEditTime: 2020-12-15 19:24:11
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, s, d;
int dis[505], w[505];         //dis储存到起点的最小距离，w储存到起点的最小金额
int g[505][505], t[505][505]; //g表示距离，t表示路费
bool vis[505];
void dijkstra()
{
    memset(dis, INF, sizeof(dis));
    dis[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int k = -1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && (k == -1 || dis[k] > dis[j]))
                k = j;
        }
        vis[k] = 1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && dis[j] > dis[k] + g[j][k])
            {
                dis[j] = dis[k] + g[j][k];
                w[j] = w[k] + t[j][k];
            }
            else if (!vis[j] && dis[j] == dis[k] + g[j][k] && w[j] > w[k] + t[j][k])
            {
                w[j] = w[k] + t[j][k];
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &d);
    memset(g, INF, sizeof(g));
    memset(t, INF, sizeof(t));
    for (int i = 0; i < m; i++)
    {
        int x, y, len, cost;
        scanf("%d%d%d%d", &x, &y, &len, &cost);
        g[x][y] = g[y][x] = len;
        t[x][y] = t[y][x] = cost;
    }
    dijkstra();
    printf("%d %d\n", dis[d], w[d]);
    return 0;
}
