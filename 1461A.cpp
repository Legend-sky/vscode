/*
 * @Author: Whx
 * @Date: 2020-12-27 16:52:51
 * @LastEditTime: 2020-12-27 18:13:46
 */
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

int n, k;

inline void solve()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n / 3; i++)
    {
        printf("abc");
    }
    if (n % 3 == 1)
        printf("a");
    if (n % 3 == 2)
    {
        printf("ab");
    }
    printf("\n");
}
int main()
{
    int T = 1;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        solve();
    }
    return 0;
}
