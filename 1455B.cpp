/*
 * @Author: Whx
 * @Date: 2020-12-02 17:07:00
 * @LastEditTime: 2020-12-02 17:09:03
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
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
        if (sum == n || sum > n + 1)
        {
            cout << i << endl;
            break;
        }
        if (sum == n + 1)
        {
            cout << i + 1 << endl;
            break;
        }
    }
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
