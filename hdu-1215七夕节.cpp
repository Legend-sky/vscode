/*
 * @Author: Whx
 * @Date: 2020-12-25 22:15:48
 * @LastEditTime: 2020-12-25 22:44:02
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
int f[500005];
int main()
{
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= 500000; i++)
    {
        for (int j = 2 * i; j <= 500000; j += i)
        {
            f[j] += i;
        }
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int k;
        scanf("%d", &k);
        printf("%d\n", f[k]);
    }
    // int t;
    // scanf("%d", &t);
    // while (t--)
    // {
    //     int n, res = 0;
    //     scanf("%d", &n);
    //     for (int i = 1; i * i <= n; i++)
    //     {
    //         if (n % i == 0)
    //         {
    //             res += i;
    //             if (i != 1 && i != n / i)
    //             {
    //                 res += n / i;
    //             }
    //         }
    //     }
    //     printf("%d\n", res);
    // }
    return 0;
}