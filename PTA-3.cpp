/*
 * @Author: Whx
 * @Date: 2021-01-01 19:46:06
 * @LastEditTime: 2021-01-01 19:47:40
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
    int x, y, z;
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d%d", &x, &y, &z);
        if (x * x + y * y + z * z == 3 * x * y * z)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
