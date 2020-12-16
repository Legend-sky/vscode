/*
 * @Author: Whx
 * @Date: 2020-12-15 14:14:01
 * @LastEditTime: 2020-12-15 14:36:30
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int K, a, b, c, t;
int vis[55][55][55];
int dir[6][3] = {0, 0, -1, -1, 0, 0, 0, 0, 1, 1, 0, 0, 0, -1, 0, 0, 1, 0};
struct node
{
    int x, y, z, steps;
} st, en, tmp, ne;
bool check(node q)
{
    if (q.x >= 0 && q.x < a && q.y >= 0 && q.y < b && q.z >= 0 && q.z < c)
        return 1;
    return 0;
}
int bfs()
{
    queue<node> q;
    vis[st.x][st.y][st.z] = 1;
    q.push(st);
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        if (tmp.steps > t)
            return -1;
        if (tmp.x == en.x && tmp.y == en.y && tmp.z == en.z)
        {
            return tmp.steps;
        }
        for (int i = 0; i < 6; i++)
        {
            ne.x = tmp.x + dir[i][0];
            ne.y = tmp.y + dir[i][1];
            ne.z = tmp.z + dir[i][2];
            if (!vis[ne.x][ne.y][ne.z] && check(ne))
            {
                ne.steps = tmp.steps + 1;
                vis[ne.x][ne.y][ne.z] = 1;
                q.push(ne);
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d", &K);
    while (K--)
    {
        memset(vis, 0, sizeof(vis));
        scanf("%d%d%d%d", &a, &b, &c, &t);
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                for (int k = 0; k < c; k++)
                    scanf("%d", &vis[i][j][k]);
        st.x = 0, st.y = 0, st.z = 0, st.steps = 0;
        en.x = a - 1, en.y = b - 1, en.z = c - 1, en.steps = 0;
        int res = bfs();
        printf("%d\n", res);
    }
    return 0;
}