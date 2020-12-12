/*
 * @Author: Whx
 * @Date: 2020-11-16 19:50:39
 * @LastEditTime: 2020-11-16 21:56:29
 */
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n, a, b;
int vis[205];
int k[205];
struct node
{
    int level;
    int steps;
};
void bfs()
{
    node cur, nex;
    queue<node> q;
    cur.level = a;
    cur.steps = 0;
    q.push(cur);
    vis[cur.level] = 1;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur.level == b)
        {
            cout << cur.steps << endl;
            return;
        }
        nex.level = cur.level + k[cur.level];
        if (nex.level <= n && !vis[nex.level])
        {
            vis[nex.level] = 1;
            nex.steps = cur.steps + 1;
            q.push(nex);
        }
        nex.level = cur.level - k[cur.level];
        if (nex.level >= 1 && !vis[nex.level])
        {
            vis[nex.level] = 1;
            nex.steps = cur.steps + 1;
            q.push(nex);
        }
    }
    cout << -1 << endl;
    return;
}
int main()
{
    while (cin >> n, n)
    {
        memset(vis, 0, sizeof(vis));
        cin >> a >> b;
        for (int i = 1; i <= n; i++)
            cin >> k[i];
        bfs();
    }
    return 0;
}