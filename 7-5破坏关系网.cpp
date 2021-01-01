/*
 * @Author: Whx
 * @Date: 2020-12-22 19:28:29
 * @LastEditTime: 2020-12-26 20:32:59
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
int n, m;
int g[35][35];
int vis[35], dis[35];
int dijkstra(int t)
{
    memset(dis, INF, sizeof(dis));
    dis[1] = 0;
    int gg[35][35];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            gg[i][j] = g[i][j];
            if (i == t || j == t)
                gg[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int k = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && (k == -1 || dis[k] > dis[j]))
                k = j;
        }
        vis[k] = 1;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dis[j] > dis[k] + gg[j][k])
                dis[j] = dis[k] + gg[j][k];
        }
    }
    if (dis[n] == INF)
        return -1;
    else
        return dis[n];
}
int main()
{
    scanf("%d%d", &n, &m);
    memset(g, INF, sizeof(g));
    for (int i = 0; i < m; i++)
    {
        int a, b, len;
        scanf("%d%d%d", &a, &b, &len);
        g[a][b] = g[b][a] = len;
    }
    int res = 0;
    int tmp;
    for (int i = 2; i < n; i++)
    {
        memset(vis, 0, sizeof(vis));
        tmp = dijkstra(i);
        if (tmp == -1)
        {
            printf("Fail\n");
            break;
        }
        res = max(res, tmp);
    }
    if (tmp != -1)
        printf("%d\n", res);
    return 0;
}