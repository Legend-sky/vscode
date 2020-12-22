/*
 * @Author: Whx
 * @Date: 2020-12-19 18:25:21
 * @LastEditTime: 2020-12-19 18:28:49
 */
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

int n;
long long f[1005];

inline void solve()
{
    scanf("%d", &n);
    printf("%d", f[n]);
}
int main()
{
    f[0] = 1;
    f[1] = 4;
    f[2] = 4;
    f[3] = 12;
    for (int i = 4; i <= 1000; i++)
    {
        if (i % 2 == 0)
        {
            f[i] = f[i - 4] + 2 * i;
        }
        else
        {
            f[i] = f[i - 2] + 2 * (i + 1);
        }
    }
    solve();
    return 0;
}
