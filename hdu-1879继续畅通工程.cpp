/*
 * @Author: Whx
 * @Date: 2020-12-14 21:57:02
 * @LastEditTime: 2020-12-14 22:03:20
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct node
{
    int from, to, dis;
} edge[100005];
int f[10005];
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
    int n, k;
    while (scanf("%d", &n), n)
    {
        for (int i = 1; i <= n; i++)
            f[i] = i;
        n = n * (n - 1) / 2;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d%d", &edge[i].from, &edge[i].to, &edge[i].dis, &k);
            if (k == 1)
                edge[i].dis = 0;
        }
        sort(edge, edge + n, cmp);
        int res = 0;
        for (int i = 0; i < n; i++)
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