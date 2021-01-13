/*
 * @Author: Whx
 * @Date: 2021-01-13 13:26:48
 * @LastEditTime: 2021-01-13 14:35:43
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define ll long long

using namespace std;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;
ll dp[100005];
int main()
{
    ll p1, p2, p3, i;
    while (cin >> p1 >> p2 >> p3 >> i)
    {
        dp[1] = 1;
        ll a = 1, b = 1, c = 1, f[3];
        for (int k = 2; k <= i + 1; k++)
        {
            f[0] = dp[a] * p1;
            f[1] = dp[b] * p2;
            f[2] = dp[c] * p3;
            sort(f, f + 3);
            dp[k] = f[0];
            if (dp[k] == dp[a] * p1)
                a++;
            if (dp[k] == dp[b] * p2)
                b++;
            if (dp[k] == dp[c] * p3)
                c++;
        }
        cout << dp[i + 1] << endl;
    }
    return 0;
}
