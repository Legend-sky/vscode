/*
 * @Author: Whx
 * @Date: 2020-12-18 16:23:41
 * @LastEditTime: 2020-12-18 17:36:00
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int line[205][205];
bool vis[205];
int h[205];
int n, k; //n个节点，k条边
bool find(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && line[x][i])
        {
            vis[i] = 1;
            if (h[i] == -1 || find(h[i]))
            {
                h[i] = x;
                return true;
            }
        }
    }
    return false;
}
inline void solve()
{
    memset(line, 0, sizeof(line));
    memset(h, -1, sizeof(h));
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        line[a][b] = 1;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if (find(i))
            res++;
    }
    printf("%d\n", n - res);
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}