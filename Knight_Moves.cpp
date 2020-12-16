/*
 * @Author: Whx
 * @Date: 2020-12-15 12:46:33
 * @LastEditTime: 2020-12-15 13:20:57
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int vis[10][10];
int dir[8][2] = {-1, -2, -2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2};
struct node
{
    int x, y, steps;
} st, en, nx;
bool check(node q)
{
    if (q.x <= 0 || q.x >= 9 || q.y <= 0 || q.y >= 9)
        return 0;
    return 1;
}
int bfs()
{
    queue<node> q;
    q.push(st);
    vis[st.x][st.y] = 1;
    node tmp;
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        if (tmp.x == en.x && tmp.y == en.y)
        {
            return tmp.steps;
        }
        for (int i = 0; i < 8; i++)
        {
            nx.x = tmp.x + dir[i][0];
            nx.y = tmp.y + dir[i][1];
            if (!vis[nx.x][nx.y] && check(nx))
            {
                nx.steps = tmp.steps + 1;
                vis[nx.x][nx.y] = 1;
                q.push(nx);
            }
        }
    }
    return 0;
}
int main()
{
    char a, b;
    int x, y;
    while (cin >> a >> x >> b >> y)
    {
        memset(vis, 0, sizeof(vis));
        st.x = x;
        st.y = int(a - 96);
        st.steps = 0;
        en.x = y;
        en.y = int(b - 96);
        st.steps = 0;
        int res = bfs();
        printf("To get from %s to %s takes %d knight moves.\n", a, x, b, y, res);
    }
    return 0;
}
