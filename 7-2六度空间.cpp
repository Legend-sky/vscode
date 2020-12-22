/*
 * @Author: Whx
 * @Date: 2020-12-22 20:44:28
 * @LastEditTime: 2020-12-22 22:21:56
 */
#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, cnt, G[1005][1005], vis[1005];
struct Node
{
    int n, d;
};
void BFS(int n)
{
    queue<Node> q;
    Node no;
    no.n = n;
    no.d = 0;
    vis[n] = 1;
    q.push(no);
    while (!q.empty())
    {
        Node tmp = q.front();
        q.pop();
        cnt++;
        if (tmp.d == 7)
            continue;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 1)
                continue;
            if (G[tmp.n][i] == 0)
                continue;
            Node node;
            node.n = i;
            node.d = tmp.d + 1;
            vis[i] = 1;
            q.push(node);
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(G, 0, sizeof(G));
        memset(vis, 0, sizeof(vis));
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            G[a][b] = G[b][a] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            memset(vis, 0, sizeof(vis));
            cnt = 0;
            BFS(i);
        }
        if (cnt == n)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}