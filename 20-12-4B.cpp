/*
 * @Author: Whx
 * @Date: 2020-12-04 21:49:37
 * @LastEditTime: 2020-12-04 22:14:39
 */
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

int n;
int a[N];

inline void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int tmp = 0;
    tmp = max(abs(a[0] - a[1]), abs(a[n - 1] - a[n - 2]));
    for (int i = 1; i < n - 1; i++)
    {
        if (abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]) - (abs(a[i - 1] - a[i + 1])) > tmp)
            if (a[i] > max(a[i - 1], a[i + 1]) || a[i] < min(a[i - 1], a[i + 1]))
                tmp = abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]) - (abs(a[i - 1] - a[i + 1]));
    }
    ll res = -tmp;
    for (int i = 1; i < n; i++)
    {
        res += abs(a[i] - a[i - 1]);
    }
    printf("%lld\n", res);
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
