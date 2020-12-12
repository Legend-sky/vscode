/*
 * @Author: Whx
 * @Date: 2020-12-10 19:28:04
 * @LastEditTime: 2020-12-10 22:17:51
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
vector<int> G[1005];
int vis[1005];
int n, m, cnt;
void bfs(int k)
{
    queue<int> q;
    q.push(k);
    vis[k] = 1;
    cnt++;
    for (int i = 0; i < 6; i++)
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
            int p = v[i];
            for (int j = 0; j < G[p].size(); j++)
            {
                if (vis[G[p][j]] == 0)
                {
                    vis[G[p][j]] = 1;
                    cnt++;
                    q.push(G[p][j]);
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) //邻接表存储
    {
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        cnt = 0;
        memset(vis, 0, sizeof(vis));
        bfs(i);
        double res = cnt * 1.0 / n;
        printf("%d: %.2f%%\n", i, res * 100);
    }
    return 0;
}