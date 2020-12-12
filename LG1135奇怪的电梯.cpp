/*
 * @Autor: Whx
 * @Date: 2020-11-11 22:11:32
 * @LastEditTime: 2020-11-11 22:24:22
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct pos
{
    int level;
    int steps;
};

int N, A, B, ans;
int vis[205];
int a[205];

int bfs()
{
    pos cur, next;
    cur.level = A;
    cur.steps = 0;
    queue<pos> q;
    q.push(cur);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur.level == B)
        {
            return cur.steps;
        }
        next.level = cur.level + a[cur.level];
        next.steps = cur.steps + 1;
        if (next.level <= N && !vis[next.level])
        {
            vis[next.level] = 1;
            q.push(next);
        }
        next.level = cur.level - a[cur.level];
        next.steps = cur.steps + 1;
        if (next.level >= 1 && !vis[next.level])
        {
            vis[next.level] = 1;
            q.push(next);
        }
    }
    return -1;
}
int main()
{
    memset(vis, 0, sizeof(vis));
    cin >> N >> A >> B;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    vis[A] = 1;
    ans = bfs();
    cout << ans;
}
