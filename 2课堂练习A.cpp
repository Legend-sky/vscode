/*
 * @Author: Whx
 * @Date: 2021-01-06 18:31:45
 * @LastEditTime: 2021-01-06 18:35:52
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define ll long long

using namespace std;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

int main()
{
    int t, n, a[100];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int sum = 0;
        double aver = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        aver = sum * 1.0 / n;
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= aver)
            {
                num++;
            }
        }
        printf("%.2lf %d\n", aver, num);
    }
    return 0;
}
