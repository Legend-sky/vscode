/*
 * @Author: Whx
 * @Date: 2020-11-16 23:09:23
 * @LastEditTime: 2020-11-16 23:51:33
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int t, n, m;
int p, h, c;
int dp[105];
struct Mice
{
    int p, h;
};
vector<Mice> mice;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            mice.clear();
            cin >> p >> h >> c;
            for (int r = 1; r <= c; r <<= 1)
            {
                c -= r;
                mice.push_back({p * r, h * r});
            }
            if (c > 0)
                mice.push_back({p * c, h * c});
            for (auto mi : mice)
                for (int j = n; j >= mi.p; j--)
                    dp[j] = max(dp[j], dp[j - mi.p] + mi.h);
        }
        cout << dp[n] << endl;
    }
}