/*
 * @Author: Whx
 * @Date: 2020-11-21 22:32:13
 * @LastEditTime: 2020-11-22 17:12:49
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

int num;

inline void solve()
{
    cin >> num;
    if (num < 4)
        cout << num - 1 << endl;
    else
        cout << 2 + (num % 2) << endl;
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
