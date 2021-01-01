/*
 * @Author: Whx
 * @Date: 2021-01-01 16:41:32
 * @LastEditTime: 2021-01-01 17:15:40
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
bool vis[10005];
int GetSG(int x)
{
    memset(vis, 0, sizeof(vis));
    for (int j = 0; j < k && s[j] <= x; j++)
    {
        if (sg[x - s[j]] == -1)
            sg[x - s[j]] = GetSG(x - s[j]);
        vis[sg[x - s[j]]] = 1;
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
    while (scanf("%d", &k) != EOF, k)
    {
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &s[i]);
        }
        sort(s, s + k);
        scanf("%d", &m);
        memset(sg, -1, sizeof(sg));
        sg[0] = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &l);
            int res = 0;
            for (int j = 0; j < l; j++)
            {
                scanf("%d", &h);
                if (sg[h] == -1)
                    sg[h] = GetSG(h);
                res = res ^ sg[h];
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
