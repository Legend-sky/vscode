/*
 * @Author: Whx
 * @Date: 2020-12-01 22:33:59
 * @LastEditTime: 2020-12-01 22:51:14
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int a[10005];
double b[10005], f[10005], m;
int main()
{
    while (scanf("%d %lf", &n, &m) == 2)
    {
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i <= n; i++)
            f[i] = 1;
        // for (int i = 0; i < n; i++)
        //     printf("%lf\n", f[i]);
        for (int i = 0; i < m; i++)
        {
            scanf("%d %lf", &a[i], &b[i]);
            b[i] = 1 - b[i];
        }
        for (int i = 0; i < m; i++)
            for (int j = n; j >= a[i]; j--)
                f[j] = min(f[j], f[j - a[i]] * b[i]);
        double ans = f[n];
        ans = (1 - ans) * 100;
        printf("%.1lf%%\n", ans);
    }
    return 0;
}