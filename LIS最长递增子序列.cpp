/*
 * @Author: Whx
 * @Date: 2021-01-03 10:24:24
 * @LastEditTime: 2021-01-03 10:28:54
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define ll long long

using namespace std;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;
int n, a[100];
int dp[100]; //dp[i]表示以a[i]结尾的最长递增子序列的长度
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int cnt = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[i] > a[j])
            {
                cnt = max(cnt, dp[j] + 1);
            }
        }
        dp[i] = cnt;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
    return 0;
}
