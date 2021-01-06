/*
 * @Author: Whx
 * @Date: 2021-01-06 18:56:11
 * @LastEditTime: 2021-01-06 19:03:36
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define ll long long

using namespace std;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;
int j[1005], f[1005];
int dp[1005];
int main()
{
    int n, m;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        if (n == -1 && m == -1)
            break;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &j[i], &f[i]);
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            for (int v = m; v >= f[i]; v--)
                dp[v] = max(dp[v], dp[v - f[i]] + j[i]);
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}
