/*
 * @Author: Whx
 * @Date: 2020-12-08 19:34:39
 * @LastEditTime: 2020-12-22 19:01:57
 */
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, tot, k = 0;
int fat[10005];
struct node
{
    int from, to, dis;
} edge[1000001];
bool cmp(node &a, node &b)
{
    return a.dis < b.dis;
}
int find(int x)
{
    if (fat[x] == x)
        return x;
    else
        return find(fat[x]);
}
void unionn(int x, int y)
{
    fat[find(y)] = find(x);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].dis);
    for (int i = 1; i <= n; i++)
        fat[i] = i;
    sort(edge + 1, edge + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        if (k == n - 1) //n个点需要n-1条边
            break;
        if (find(edge[i].from) != find(edge[i].to))
        {
            unionn(edge[i].from, edge[i].to);
            tot += edge[i].dis;
            k++;
        }
    }
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        if (fat[i] == i)
            t++;
    }
    if (t > 1)
        printf("-1");
    else
        printf("%d", tot);
    return 0;
}