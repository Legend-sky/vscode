/*
 * @Author: Whx
 * @Date: 2020-12-03 22:42:37
 * @LastEditTime: 2020-12-03 22:51:23
 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int G[1005][1005];
int vis[1005];
int cnt[1005];
int v, e, s;
void dfs(int a, stack<int> &prev, int f)
{
    vis[a] = 1;
    prev.push(a);
    if (!f)
        printf("%d", a);
    else
        printf(" %d", a);
    for (int i = 1; i < v + 1; i++)
        if (!vis[i] && G[a][i] == 1)
            dfs(i, prev, 1);
    if (!prev.empty())
    {
        prev.pop();
        if (!prev.empty())
            printf(" %d", prev.top());
    }
}
int main()
{
    scanf("%d %d %d", &v, &e, &s);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a][b] = 1;
        G[b][a] = 1;
    }
    stack<int> prev;
    memset(vis, 0, sizeof(vis));
    dfs(s, prev, 0);
    int f = 0;
    for (int i = 1; i < v + 1; i++)
    {
        if (vis[i] != 1)
            f = 1;
    }
    if (f)
        printf(" 0");
    return 0;
}