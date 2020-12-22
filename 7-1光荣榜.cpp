/*
 * @Author: Whx
 * @Date: 2020-12-22 18:29:31
 * @LastEditTime: 2020-12-22 18:34:46
 */
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n, k = 0, maxscore = 0;
    int a[100];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > maxscore)
        {
            maxscore = a[i];
            k = i;
        }
    }
    printf("%d %d", k, a[k]);
    return 0;
}