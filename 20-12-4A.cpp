/*
 * @Author: Whx
 * @Date: 2020-12-04 21:15:57
 * @LastEditTime: 2020-12-04 21:25:50
 */
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

int n, m;
int a[105], b[105];

inline void solve()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    sort(a, a + n);
    sort(b, b + m);
    int i = 0, j = 0, cnt = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            cnt++;
            i++;
            j++;
        }
        if (a[i] < b[j])
            i++;
        if (a[i] > b[j])
            j++;
    }
    printf("%d\n", cnt);
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
