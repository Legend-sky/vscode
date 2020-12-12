/*
 * @Author: Whx
 * @Date: 2020-11-17 22:36:30
 * @LastEditTime: 2020-11-17 22:48:32
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

int n, c0, c1, h;
int num1, num0;
string s;

inline void solve()
{
    cin >> n >> c0 >> c1 >> h;
    num0 = num1 = 0;
    cin >> s;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '1')
            num1++;
        else
            num0++;
    }
    int ans = min(num0 * h + (num0 + num1) * c1, num1 * h + (num0 + num1) * c0);
    ans = min(ans, num0 * c0 + num1 * c1);
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
