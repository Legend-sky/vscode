/*
 * @Autor: Whx
 * @Date: 2020-11-03 07:49:52
 * @LastEditTime: 2020-11-03 08:00:39
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

int n;

inline void solve()
{
    int a, b;
    cin >> a >> b;
    string str;
    cin >> str;
    int p = 0, ans = 0;
    while (str[p] == '0')
        p++;
    if (str[p])
        ans = a;
    int last = 0;
    for (int i = p + 1; str[i]; i++)
    {
        if (str[i] == '0' && str[i - 1] == '1')
        {
            last = i - 1;
        }
        if (str[i] == '1' && str[i - 1] == '0')
        {
            ans += min((i - last - 1) * b, a);
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        solve();
    }
    return 0;
}
