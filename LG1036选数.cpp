/*
 * @Author: Whx
 * @Date: 2020-12-08 08:18:06
 * @LastEditTime: 2020-12-08 08:37:37
 */
#include <cstdio>
using namespace std;
int n, k, a[25];
long long ans;
bool isprime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}
void dfs(int m, int sum, int start_min) //start_min是选出的序列中的小标最小的，避免算重
{
    if (m == k)
    {
        if (isprime(sum))
            ans++;
        return;
    }
    for (int i = start_min; i < n; i++)
        dfs(m + 1, sum + a[i], i + 1);
    return;
}
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    ans = 0;
    dfs(0, 0, 0);
    printf("%d\n", ans);
    return 0;
}