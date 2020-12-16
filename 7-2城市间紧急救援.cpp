/*
 * @Author: Whx
 * @Date: 2020-12-15 19:43:09
 * @LastEditTime: 2020-12-15 20:28:56
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
int g[505][505]; //城市之间的路径
int cnt[505];    //最短路径的条数
int vis[505];    //节点是否被拜访
int f[505];      //各城市救援队数量
int ff[505];     //到达该城市时所召集的救援队数量
int pre[505];
int n, m, s, d;
void dijkstra()
{
    vis[s] = 1; //刚开始设定起点被拜访过
    cnt[s] = 1;
    for (int i = 0; i < n; i++)
    {
        int Min = INF, k = -1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && g[s][j] < Min)
            {
                Min = g[s][j];
                k = j;
            }
        }
        if (k == -1)
            break;
        vis[k] = 1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && g[s][j] > g[s][k] + g[k][j])
            {
                g[s][j] = g[s][k] + g[k][j];
                pre[j] = k;
                cnt[j] = cnt[k];
                ff[j] = f[j] + ff[k];
            }
            else if (!vis[j] && g[s][j] == g[s][k] + g[k][j])
            {
                cnt[j] += cnt[k];
                if (ff[j] < ff[k] + f[j])
                {
                    ff[j] = ff[k] + f[j];
                    pre[j] = k;
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &f[i]);
        ff[i] = f[i];
        cnt[i] = 1;
    }
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (i != j)
                g[i][j] = g[j][i] = INF;
    for (int i = 0; i < m; i++)
    {
        int a, b, len;
        scanf("%d%d%d", &a, &b, &len);
        g[a][b] = g[b][a] = len;
    }
    dijkstra();
    printf("%d %d\n", cnt[d], ff[d] + f[s]); //起点刚开始被拜访过，没有记入救援数量
    int road[505];
    int count = 1, t = d;
    road[0] = d;
    while (pre[t] != 0)
    {
        road[count++] = pre[t];
        t = pre[t];
    }
    printf("%d", s);
    for (int i = count - 1; i >= 0; i--)
    {
        printf(" %d", road[i]);
    }
    return 0;
}