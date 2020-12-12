/*
 * @Autor: Whx
 * @Date: 2020-10-28 18:52:33
 * @LastEditTime: 2020-10-28 20:00:04
 */
#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

long long n;

inline void solve()
{
    int num[4] = {2, 3, 5, 7};
    while (cin >> n, n)
    {
        int a[4] = {1, 1, 1, 1};
        long long res = 0;
        for (int i = 0; i < 4; i++)
        {
            while (n % num[i] == 0)
            {
                a[i]++;
                n /= num[i];
            }
        }
        res = a[0] * a[1] * a[2] * a[3];
        cout << res << endl;
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