/*
 * @Author: Whx
 * @Date: 2020-12-23 22:33:04
 * @LastEditTime: 2020-12-24 14:39:20
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int m[105][105];
int ans[105][105];
int dir[4][2] = {0, -1, -1, 0, 0, 1, 1, 0};
int n, k;
bool check(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}
int dfs(int x, int y)
{
    int res = 0;
    if (ans[x][y])
        return ans[x][y];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int nx = x + dir[i][0] * j;
            int ny = y + dir[i][1] * j;
            if (check(nx, ny) && m[nx][ny] > m[x][y]) //check一定要放前面，否则数组会越界！！
            {
                res = max(res, dfs(nx, ny));
            }
        }
    }
    ans[x][y] = res + m[x][y];
    return ans[x][y];
}
int main()
{
    while (scanf("%d%d", &n, &k) == 2)
    {
        memset(ans, 0, sizeof(ans));
        if (n == -1 && k == -1)
            break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &m[i][j]);
        printf("%d\n", dfs(0, 0));
    }
    return 0;
}