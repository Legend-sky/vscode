/*
 * @Author: Whx
 * @Date: 2020-12-14 18:33:15
 * @LastEditTime: 2020-12-14 19:26:00
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct node
{
    int from, to, dis;
} edge[10005];
int f[105];
bool cmp(node a, node b)
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
    int n, q, m[105][105], a, b;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= 100; i++)
            f[i] = i;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &m[i][j]);
        scanf("%d", &q);
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d", &a, &b);
            m[a][b] = m[b][a] = 0;
        }
        int cnt = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                edge[cnt].from = i;
                edge[cnt].to = j;
                edge[cnt].dis = m[i][j];
                cnt++;
            }
        }
        sort(edge, edge + cnt, cmp);
        int res = 0;
        for (int i = 0; i < cnt; i++)
        {
            int xx = find(edge[i].from);
            int yy = find(edge[i].to);
            if (xx != yy)
            {
                f[yy] = xx;
                res += edge[i].dis;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}