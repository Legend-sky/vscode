/*
 * @Author: Whx
 * @Date: 2020-12-24 22:19:12
 * @LastEditTime: 2020-12-24 22:48:54
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int mod = 10000;
int ma[105][105];
int re[105][105];
int t, n, m;
int dfs(int x, int y)
{
    if (re[x][y] >= 0)
        return re[x][y];
    re[x][y] = 0;
    for (int i = 0; i <= ma[x][y]; i++)
    {
        for (int j = 0; j <= ma[x][y] - i; j++)
        {
            if (x + i >= 1 && x + i <= n && y + j >= 1 && y + j <= m)
                re[x][y] = (dfs(x + i, y + j) + re[x][y]) % mod;
        }
    }
    return re[x][y];
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(re, -1, sizeof(re));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &ma[i][j]);
        re[n][m] = 1;
        // dfs(1, 1);
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= m; j++)
        //     {
        //         printf("%d ", re[i][j]);
        //     }
        //     printf("\n");
        // }
        printf("%d\n", dfs(1, 1));
    }
    return 0;
}