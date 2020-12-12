/*
 * @Autor: Whx
 * @Date: 2020-10-28 18:42:21
 * @LastEditTime: 2020-10-28 18:49:03
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
int num[4] = {2, 3, 5, 7};
inline void solve()
{
    cin >> n;
    for (int i = 0; i < 4; i++)
    {
        int k = num[i];
        while (n % k == 0)
            n /= k;
    }
    if (n == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
