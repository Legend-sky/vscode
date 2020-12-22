/*
 * @Author: Whx
 * @Date: 2020-12-22 20:44:28
 * @LastEditTime: 2020-12-22 22:21:31
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int> G[10005];
int n, m;
int cnt;
int vis[10005];
void BFS(int id)
{
    queue<int> q;
    q.push(id);
    vis[id] = 1;
    cnt++;
    for (int deep = 0; deep < 6; deep++)
    {
        vector<int> v;
        while (!q.empty())
        {
            int tmp = q.front();
            q.pop();
            v.push_back(tmp);
        }
        for (int i = 0; i < v.size(); i++)
        {
            int xx = v[i];
            for (int j = 0; j < G[xx].size(); j++)
            {
                int index = G[xx][j];
                if (vis[index] == 0)
                {
                    vis[index] = 1;
                    cnt++;
                    q.push(index);
                }
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            cnt = 0;
            memset(vis, 0, sizeof(vis));
            BFS(i);
        }
        if (cnt == n)
            printf("Yes\n");
        else
            printf("No\n");
        G->clear();
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}