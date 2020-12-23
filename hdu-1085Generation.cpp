/*
 * @Author: Whx
 * @Date: 2020-12-23 21:45:46
 * @LastEditTime: 2020-12-23 22:30:11
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int c1[10005], c2[10005];
int main()
{
    int num[5], n, p;
    int elem[4] = {0, 1, 2, 5};
    while (scanf("%d%d%d", &num[1], &num[2], &num[3]) == 3)
    {
        if (num[1] == 0 && num[2] == 0 && num[3] == 0)
            break;
        n = num[1] + 2 * num[2] + 5 * num[3];
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        for (int i = 0; i <= num[1]; i++)
        {
            c1[i] = 1;
        }
        p = num[1];
        for (int i = 2; i <= 3; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                for (int k = 0; (k + j <= n) && (k <= elem[i] * num[i]); k += elem[i])
                {
                    c2[k + j] += c1[j];
                }
            }
            for (int j = 0; j <= n; j++)
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        for (int i = 0; i <= n + 1; i++)
        {
            if (c1[i] == 0)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}