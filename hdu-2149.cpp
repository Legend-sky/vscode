/*
 * @Author: Whx
 * @Date: 2021-01-01 15:36:17
 * @LastEditTime: 2021-01-01 16:14:36
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int m, n;
int main()
{
    while (scanf("%d%d", &m, &n) != EOF)
    {
        if (m % (n + 1) == 0)
        {
            printf("none\n");
            continue;
        }
        printf("%d", m % (n + 1));
        for (int i = m + 1; i <= n; i++)
        {
            printf(" %d", i);
        }
        printf("\n");
    }
    return 0;
}