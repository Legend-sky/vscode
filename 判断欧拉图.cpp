/*
 * @Author: Whx
 * @Date: 2020-12-03 20:50:44
 * @LastEditTime: 2020-12-03 22:14:57
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
int edge[1005], f[1005];
int find(int a)
{
    if (f[a] == a)
        return a;
    else
    {
        f[a] = find(f[a]);
        return f[a];
    }
}
void merge(int a, int b)
{
    int t1, t2;
    t1 = find(a);
    t2 = find(b);
    if (t1 != t2)
        f[t2] = t1;
}
int main()
{
    memset(edge, 0, sizeof(edge));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        edge[x]++;
        edge[y]++;
        merge(x, y);
    }
    int t = 0;
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == i)
            t++;
        if (edge[i] % 2 != 0)
        {
            flag = false;
            break;
        }
    }
    if (t == 1 && flag)
        printf("1\n");
    else
        printf("0\n");
    return 0;
}