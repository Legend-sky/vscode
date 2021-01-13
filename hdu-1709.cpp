/*
 * @Author: Whx
 * @Date: 2021-01-11 16:33:03
 * @LastEditTime: 2021-01-11 16:43:00
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
int c1[10005], c2[10005];
int p[105], ans[10005];
int main()
{
    int n;
    int sum, res;
    while (scanf("%d", &n) == 1)
    {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &p[i]);
            sum += p[i];
        }
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        c1[0] = c1[p[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < sum; j++)
            {
                for (int k = -p[i]; k <= p[i]; k += p[i]) //每个项只有三个项数
                {
                    c2[j + k > 0 ? j + k : -j - k] += c1[j];
                }
            }
            for (int j = 0; j <= sum; j++)
            {
                c1[j] = c2[j] ? 1 : 0;
                c2[j] = 0;
            }
        }
        res = 0;
        for (int i = 0; i <= sum; i++)
        {
            if (!c1[i])
            {
                ans[res++] = i;
            }
        }
        if (!res)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n%d", res, ans[0]);
            for (int i = 1; i < res; i++)
            {
                printf(" %d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
