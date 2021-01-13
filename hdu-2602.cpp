/*
 * @Author: Whx
 * @Date: 2021-01-13 15:36:18
 * @LastEditTime: 2021-01-13 16:20:06
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define ll long long

using namespace std;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;
int dp[1005];
int w[1005], c[1005];
int main()
{
    int N, V, T;
    cin >> T;
    while (T--)
    {
        cin >> N >> V;
        for (int i = 0; i < N; i++)
            cin >> w[i]; //物品价值
        for (int i = 0; i < N; i++)
            cin >> c[i]; //物品体积
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < N; i++)
        {
            for (int v = V; v >= c[i]; v--)
                dp[v] = max(dp[v], dp[v - c[i]] + w[i]);
        }
        cout << dp[V] << endl;
    }
    return 0;
}
