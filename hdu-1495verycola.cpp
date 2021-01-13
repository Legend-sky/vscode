/*
 * @Author: Whx
 * @Date: 2020-12-13 21:51:20
 * @LastEditTime: 2020-12-13 22:16:39
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int v[5];
int vis[105][105][105];
struct cup //记录水杯的情况
{
    int v[5];
    int step;
} temp;
void pour(int a, int b) //把a中的可乐倒进b中
{
    int sum = temp.v[a] + temp.v[b];
    if (sum >= v[b])
        temp.v[b] = v[b];
    else
        temp.v[b] = sum;
    temp.v[a] = sum - temp.v[b];
}
void bfs()
{
    int i, j;
    queue<cup> q;
    cup a;
    a.v[1] = v[1];
    a.v[2] = 0;
    a.v[3] = 0;
    a.step = 0;
    q.push(a);
    memset(vis, 0, sizeof(vis));
    vis[v[1]][0][0] = 1;
    while (!q.empty())
    {
        a = q.front();
        q.pop();
        if ((a.v[1] == a.v[3]) && (a.v[2] == 0))
        {
            printf("%d\n", a.step);
            return;
        }
        for (int i = 1; i < 4; i++)
        {
            for (int j = 1; j < 4; j++)
            {
                if (i != j)
                {
                    temp = a;
                    pour(i, j);
                    if (!vis[temp.v[1]][temp.v[2]][temp.v[3]])
                    {
                        temp.step++;
                        q.push(temp);
                        vis[temp.v[1]][temp.v[2]][temp.v[3]] = 1;
                    }
                }
            }
        }
    }
    printf("NO\n");
}
int main()
{
    while (scanf("%d%d%d", &v[1], &v[2], &v[3]))
    {
        if (v[1] == 0 && v[2] == 0 && v[3] == 0)
            break;
        if (v[1] % 2 == 1)
        {
            printf("NO\n");
            continue;
        }
        if (v[2] > v[3])
            swap(v[2], v[3]);
        bfs();
    }
    return 0;
}