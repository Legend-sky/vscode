/*
 * @Author: Whx
 * @Date: 2020-12-31 17:03:43
 * @LastEditTime: 2021-01-01 15:34:03
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int m, k[105], res, ans;
    while (scanf("%d", &m) != EOF, m)
    {
        ans = res = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &k[i]);
            res = res ^ k[i];
        }
        if (res == 0)
        {
            printf("0\n");
        }
        else
        {
            int p = 1;
            while (res > 0)
            {
                res >>= 1;
                p <<= 1;
            }
            p >>= 1;
            for (int i = 0; i < m; i++)
            {
                if (p & k[i])
                {
                    ans++;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}