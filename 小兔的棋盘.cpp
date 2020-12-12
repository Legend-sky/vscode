/*
 * @Autor: Whx
 * @Date: 2020-10-28 13:05:36
 * @LastEditTime: 2020-10-28 13:24:22
 */
#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

int n;
long long dp[40][40];

inline void
solve(int n, int k)
{
    for (int i = 0; i < 37; i++)
        dp[0][i] = 1;
    for (int i = 1; i < 37; i++)
    {
        for (int j = i; j < 37; j++)
        {
            if (i == j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << k << " " << n << " " << 2 * dp[n][n] << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k = 1;
    while (cin >> n && n != -1)
    {
        solve(n, k);
        k++;
    }
    return 0;
}
