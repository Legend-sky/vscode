/*
 * @Author: Whx
 * @Date: 2020-12-14 19:48:12
 * @LastEditTime: 2020-12-14 21:53:29
 */
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
struct Node
{
    int x, y;
} node[105];
struct Edge
{
    int from, to;
    double dis;
} edge[10005];
int f[105], t, n;
bool cmp(Edge a, Edge b)
{
    return a.dis < b.dis;
}
int find(int x)
{
    if (f[x] == x)
        return f[x];
    else
        return find(f[x]);
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            f[i] = i;
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &node[i].x, &node[i].y);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                edge[cnt].from = i;
                edge[cnt].to = j;
                edge[cnt].dis = sqrt((node[i].x - node[j].x) * (node[i].x - node[j].x) + (node[i].y - node[j].y) * (node[i].y - node[j].y));
                cnt++;
            }
        }
        sort(edge, edge + cnt, cmp);
        double res = 0;
        for (int i = 0; i < cnt; i++)
        {
            int xx = find(edge[i].from);
            int yy = find(edge[i].to);
            if (xx != yy && (edge[i].dis >= 10 && edge[i].dis <= 1000))
            {
                f[yy] = xx;
                res += edge[i].dis;
            }
        }
        int root = 0;
        for (int i = 1; i <= n; i++)
        {
            if (f[i] == i)
                root++;
        }
        if (root > 1)
            printf("oh!\n");
        else
            printf("%.1lf\n", res * 100);
    }
    return 0;
}