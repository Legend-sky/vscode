/*
 * @Author: Whx
 * @Date: 2020-12-29 22:29:55
 * @LastEditTime: 2020-12-30 16:02:43
 */
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n, m, t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        if (n % (m + 1) == 0)
        {
            printf("second\n");
        }
        else
        {
            printf("first\n");
        }
    }
    return 0;
}