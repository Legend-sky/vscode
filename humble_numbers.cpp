/*
 * @Autor: Whx
 * @Date: 2020-10-28 15:27:20
 * @LastEditTime: 2020-10-28 16:01:51
 */
#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

int dp[5850];
int n;
int num[5];

inline void solve(int n)
{
    string s;
    if (n % 100 >= 11 && n % 100 <= 13)
        s = "th";
    else
    {
        if (n % 10 == 1)
            s = "st";
        else if (n % 10 == 2)
            s = "nd";
        else if (n % 10 == 3)
            s = "rd";
        else
            s = "th";
    }
    cout << "The " << n << s << " humble number is " << dp[n] << "." << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dp[1] = 1;
    num[1] = num[2] = num[3] = num[4] = 1;
    for (int i = 2; i <= 5842; i++)
    {
        dp[i] = min(2 * dp[num[1]], min(3 * dp[num[2]], min(5 * dp[num[3]], 7 * dp[num[4]])));
        if (dp[num[1]] * 2 == dp[i])
            num[1]++;
        if (dp[num[2]] * 3 == dp[i])
            num[2]++;
        if (dp[num[3]] * 5 == dp[i])
            num[3]++;
        if (dp[num[4]] * 7 == dp[i])
            num[4]++;
    }
    while (cin >> n, n)
    {
        solve(n);
    }
    return 0;
}
