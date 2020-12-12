/*
 * @Autor: Whx
 * @Date: 2020-10-28 16:04:40
 * @LastEditTime: 2020-10-28 16:40:09
 */
#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

struct Mice
{
    int w, s;
    int num;
};

bool cmp(Mice a, Mice b)
{
    return a.w < b.w || (a.w == b.w && a.s > b.s);
}

Mice mice[1005];
int dp[1005], ans[1005], pre[1005];
inline void solve()
{
    int n = 0;
    memset(pre, 0, sizeof(0));
    while (cin >> mice[n].w >> mice[n].s)
    {
        mice[n].num = n + 1;
        n++;
    }
    sort(mice, mice + n, cmp);
    int res = 0, id = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (mice[j].w < mice[i].w && mice[j].s > mice[i].s)
            {
                if (dp[i] < dp[j] + 1)
                {
                    pre[i] = j;
                    dp[i] = dp[j] + 1;
                }
            }
            if (res < dp[i])
            {
                res = dp[i];
                id = i;
            }
        }
    }
    cout << res << endl;
    int ka = 0;
    while (id != 0)
    {
        ans[ka++] = id;
        id = pre[id];
    }
    if (res == 1)
        cout << dp[0] << endl;
    while (ka > 0)
    {
        ka--;
        cout << mice[ans[ka]].num << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
