/*
 * @Author: Whx
 * @Date: 2020-11-17 23:26:37
 * @LastEditTime: 2020-11-21 19:07:43
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m;
char s[105][105];
int main()
{
    int T = 1;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%s", s[i]);
        int num = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (s[i][j] == '1')
                    num++;
        num *= 3;
        printf("%d\n", num);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (s[i][j] == '1')
                {
                    int ki = 1, kj = 1;
                    if (i == n - 1)
                        ki = -1;
                    if (j == m - 1)
                        kj = -1;
                    printf("%d %d %d %d %d %d\n", i + 1, j + 1, i + ki + 1, j + 1, i + 1, j + kj + 1);
                    printf("%d %d %d %d %d %d\n", i + 1, j + 1, i + ki + 1, j + kj + 1, i + 1, j + kj + 1);
                    printf("%d %d %d %d %d %d\n", i + 1, j + 1, i + ki + 1, j + 1, i + ki + 1, j + kj + 1);
                }
            }
        }
    }
    return 0;
}
