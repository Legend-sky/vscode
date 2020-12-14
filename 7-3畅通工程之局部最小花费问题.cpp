/*
 * @Author: Whx
 * @Date: 2020-12-11 13:52:22
 * @LastEditTime: 2020-12-14 18:45:22
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int par[10005];
int n, k, res;
struct node
{
    int from, to, dis;
} edge[10005];
bool cmp(node a, node b)
{
    return a.dis < b.dis;
}
int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return find(par[x]);
}
int main()
{
    scanf("%d", &n);
    n = n * (n - 1) / 2;
    for (int i = 0; i <= 1000; i++)
    {
        par[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &edge[i].from, &edge[i].to, &edge[i].dis, &k);
        if (k == 1)
            edge[i].dis = 0;
    }
    sort(edge, edge + n, cmp);
    res = 0;
    for (int i = 0; i < n; i++) //用并查集，如果是回路了，就不会放进去
    {
        int xx = find(edge[i].from);
        int yy = find(edge[i].to);
        if (xx != yy)
        {
            par[xx] = yy;
            res += edge[i].dis;
        }
    }
    printf("%d\n", res);
    return 0;
}