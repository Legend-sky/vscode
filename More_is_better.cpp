/*
 * @Author: Whx
 * @Date: 2020-12-14 17:45:55
 * @LastEditTime: 2020-12-14 18:28:58
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int max_n = 1e7 + 5;
int f[max_n], sum[max_n];
int n;
void init()
{
    for (int i = 1; i < max_n; i++)
    {
        f[i] = i;
        sum[i] = 1;
    }
}
int find(int x)
{
    if (f[x] == x)
        return f[x];
    else
        return find(f[x]);
}
int merge(int a, int b)
{
    int aa = find(a);
    int bb = find(b);
    if (aa != bb)
    {
        if (sum[aa] < sum[bb])
        {
            f[aa] = bb;
            sum[bb] += sum[aa];
            return sum[bb];
        }
        else
        {
            f[bb] = aa;
            sum[aa] += sum[bb];
            return sum[aa];
        }
    }
    else
        return sum[aa];
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
        {
            printf("1\n");
            continue;
        }
        init();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            res = max(res, merge(x, y));
        }
        printf("%d\n", res);
    }
}