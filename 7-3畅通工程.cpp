/*
 * @Author: Whx
 * @Date: 2020-12-22 18:52:23
 * @LastEditTime: 2020-12-22 19:03:35
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int f[5005];
int n, tot = 0, k = 0;
struct node
{
    int from, to, dis;
} edge[13000000];
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
void merge(int x, int y)
{
    f[find(y)] = find(x);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n * (n - 1) / 2; i++)
    {
        scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].dis);
    }
    for (int i = 1; i <= n; i++)
        f[i] = i;
    sort(edge + 1, edge + n * (n - 1) / 2, cmp);
    for (int i = 1; i <= n * (n - 1) / 2; i++)
    {
        if (k == n - 1)
            break;
        if (find(edge[i].from) != find(edge[i].to))
        {
            merge(edge[i].from, edge[i].to);
            tot += edge[i].dis;
            k += 1;
        }
    }
    printf("%d", tot);
    return 0;
}