/*
 * @Author: Whx
 * @Date: 2021-01-01 16:41:32
 * @LastEditTime: 2021-01-01 17:30:23
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
int k, s[105];
int m, l, h;
int sg[10005];
int GetSG(int n)
{
    bool vis[105];
    memset(vis, 0, sizeof(vis));
    for (int j = 0; j < k && s[j] <= n; j++)
    {
        if (sg[n - s[j]] == -1)
            sg[n - s[j]] = GetSG(n - s[j]);
        vis[sg[n - s[j]]] = 1;
    }
    for (int j = 0;; j++)
    {
        if (!vis[j])
        {
            return j;
        }
    }
}
int main()
{
    while (scanf("%d", &k), k)
    {
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &s[i]);
        }
        sort(s, s + k);
        scanf("%d", &m);
        memset(sg, -1, sizeof(sg));
        sg[0] = 0;
        while (m--)
        {
            scanf("%d", &l);
            int res = 0;
            while (l--)
            {
                scanf("%d", &h);
                if (sg[h] == -1)
                    sg[h] = GetSG(h);
                res ^= sg[h];
            }
            if (res == 0)
                printf("L");
            else
                printf("W");
        }
        printf("\n");
    }
    return 0;
}