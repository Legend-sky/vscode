/*
 * @Author: Whx
 * @Date: 2020-12-30 19:38:19
 * @LastEditTime: 2020-12-30 22:37:07
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
//solve 1
/*
const int N = 2e6 + 5;
int h[N];
int main()
{
    int a, b, c, d, sum;
    int p[105];
    for (int i = 1; i <= 100; i++)
    {
        p[i] = i * i;
    }
    while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF)
    {
        if ((a > 0 && b > 0 && c > 0 && d > 0) || (a < 0 && b < 0 && c < 0 && d < 0))
        {
            printf("0\n");
            continue;
        }
        memset(h, 0, sizeof(h));
        for (int i = 1; i <= 100; i++)
        {
            for (int j = 1; j <= 100; j++)
            {
                h[a * p[i] + b * p[j] + 1000000]++;
            }
        }
        sum = 0;
        for (int i = 1; i <= 100; i++)
        {
            for (int j = 1; j <= 100; j++)
            {
                sum += h[-(c * p[i] + d * p[j]) + 1000000];
            }
        }
        printf("%d\n", sum * 16);
    }
    return 0;
}
*/
//solve 2
const int N = 50021;
int g[N], f[N];
int Hash(int k)
{
    int t = k % N;
    if (t < 0)
    {
        t += N;
    }
    while (f[t] != 0 && g[t] != k)
    {
        t = (t + 1) % N;
    }
    return t;
}
int main()
{
    int a, b, c, d, p, sum;
    int t[105];
    for (int i = 1; i <= 100; i++)
    {
        t[i] = i * i;
    }
    while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF)
    {
        if (a > 0 && b > 0 && c > 0 && d > 0 || a < 0 && b < 0 && c < 0 && d < 0)
        {
            printf("0\n");
            continue;
        }
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= 100; i++)
        {
            for (int j = 1; j <= 100; j++)
            {
                int s = a * t[i] + b * t[j];
                p = Hash(s);
                g[p] = s;
                f[p]++;
            }
        }
        sum = 0;
        for (int i = 1; i <= 100; i++)
        {
            for (int j = 1; j <= 100; j++)
            {
                int s = -(c * t[i] + d * t[j]);
                p = Hash(s);
                sum += f[p];
            }
        }
        printf("%d\n", sum * 16);
    }
    return 0;
}