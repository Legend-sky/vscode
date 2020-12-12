/*
 * @Author: Whx
 * @Date: 2020-12-01 22:15:05
 * @LastEditTime: 2020-12-01 22:26:19
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, a[105], b[105], m;
long long f[100005];
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; i++)
            scanf("%d %d", &a[i], &b[i]);
        scanf("%d", &m);
        for (int i = 0; i < n; i++)
            for (int j = b[i]; j <= m; j++)
                f[j] = max(f[j], f[j - b[i]] + a[i]);
        printf("%d\n", f[m]);
    }
    return 0;
}