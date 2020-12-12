/*
 * @Author: Whx
 * @Date: 2020-12-01 23:07:36
 * @LastEditTime: 2020-12-01 23:37:56
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, k, s;
int a[105], b[105], f[105][105]; //f[j][k]表示忍耐度为j，击杀怪物数<=k个时最大的经验值
int main()
{
    while (scanf("%d %d %d %d", &n, &m, &k, &s) == 4)
    {
        memset(f, 0, sizeof(f));
        for (int i = 0; i < k; i++)
            scanf("%d %d", &a[i], &b[i]);
        for (int i = 0; i < k; i++)          //注意这里是完全背包，从前到后dp（01背包从后往前dp）
            for (int j = b[i]; j <= m; j++)  //忍耐度限制
                for (int k = 1; k <= s; k++) //怪物个数限制
                    f[j][k] = max(f[j][k], f[j - b[i]][k - 1] + a[i]);
        // for (int i = 0; i <= m; i++)
        // {
        //     for (int j = 0; j <= s; j++)
        //     {
        //         printf("%d ", f[i][j]);
        //     }
        //     printf("\n");
        // }
        if (f[m][s] < n)
        {
            printf("-1\n");
            continue;
        }
        bool flag = false;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= s; j++)
            {
                if (flag)
                    break;
                if (f[i][j] >= n)
                {
                    printf("%d\n", m - i);
                    flag = true;
                }
            }
        }
    }
    return 0;
}