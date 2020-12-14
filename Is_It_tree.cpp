/*
 * @Author: Whx
 * @Date: 2020-12-14 16:52:23
 * @LastEditTime: 2020-12-14 17:44:10
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int flag;
int pre[100005], c[100005], d[100005];
int Find(int x)
{
    int r = x;
    while (pre[r] != r)
        r = pre[r];
    int i = x, j;
    while (pre[i] != r)
    {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}
void merge(int x, int y)
{
    int fx = Find(x);
    int fy = Find(y);
    if (fx != fy)
        pre[fx] = fy;
    else
        flag = 1;
}
int main()
{
    int ka = 0, a, b, max_n = 0;
    for (int i = 1; i < 100000; i++)
        pre[i] = i;
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    flag = 0;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        if (a < 0)
            break;
        if (a == 0 && b == 0)
        {
            ka++;
            int root = 0;
            for (int i = 1; i <= max_n; i++)
            {
                if (d[i] && pre[i] == i)
                    root++;
                if (c[i] > 1)
                    flag = 1;
            }
            if (root > 1)
                printf("Case %d is not a tree.\n", ka);
            else
            {
                if (flag)
                    printf("Case %d is not a tree.\n", ka); //判断是否有环
                else
                    printf("Case %d is a tree.\n", ka);
            }
            for (int i = 1; i < 100000; i++)
                pre[i] = i;
            memset(c, 0, sizeof(c));
            memset(d, 0, sizeof(d));
            max_n = 0;
            flag = 0;
            continue;
        }
        max_n = max(max_n, a);
        max_n = max(max_n, b);
        // if (a > max_n)
        //     max_n = a;
        // if (b > max_n)
        //     max_n = b;
        merge(a, b);
        c[b]++;
        d[a] = 1;
        d[b] = 1;
    }
    return 0;
}