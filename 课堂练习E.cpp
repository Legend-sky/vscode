/*
 * @Autor: Whx
 * @Date: 2020-10-28 18:57:38
 * @LastEditTime: 2020-10-28 19:28:54
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
long long f[42], t[42];

inline void solve()
{
    f[1] = 1;
    f[2] = 1;
    f[3] = 5;
    f[4] = 9;
    f[5] = 29;
    t[1] = 1;
    t[2] = 0;
    t[3] = 4;
    t[4] = 4;
    t[5] = 20;
    for (int i = 6; i <= 40; i++)
    {
        t[i] = (t[i - 2] + t[i - 3] + t[i - 4]) * 4; //由他们而生3年前到5年前而生的数量
        f[i] = f[i - 1] + t[i] - t[i - 5];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> n;
        cout << f[n] << endl;
    }
    return 0;
}
