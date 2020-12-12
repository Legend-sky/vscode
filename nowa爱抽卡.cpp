/*
 * @Autor: Whx
 * @Date: 2020-11-13 12:23:27
 * @LastEditTime: 2020-11-13 22:28:20
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
const int p = 998244353;
ll quickpow(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = res * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return res;
}
int pre[N];
int pre1[N][11];
int dp[N];
void work()
{
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i <= n; i++)
    {
        pre[i] = 0;
        dp[i] = 0;
    }
    dp[0] = 1;
    pre[0] = 1;
    pre1[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = pre[i - 1];
        if (i > k)
        {
            dp[i] -= pre[i - k - 1];
            dp[i] = (dp[i] + p) % p;
        }
        if (i >= 10)
        {
            dp[i] += pre1[i / 10 - 1][i % 10];
            dp[i] %= p;
        }
        if (i - (m + 1) * 10 >= 0)
        {
            dp[i] -= pre1[i / 10 - m - 1][i % 10];
            dp[i] = (dp[i] + p) % p;
        }
        pre[i] = (pre[i - 1] + dp[i]) % p;
        if (i < 10)
        {
            pre1[i / 10][i % 10] = dp[i];
        }
        else
        {
            pre1[i / 10][i % 10] = (pre1[i / 10 - 1][i % 10] + dp[i]) % p;
        }
    }
    printf("%d\n", dp[n]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    scanf("%d", &T);
    while (T--)
    {
        work();
    }
}