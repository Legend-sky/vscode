/*
 * @Author: Whx
 * @Date: 2021-01-01 16:15:54
 * @LastEditTime: 2021-01-01 16:22:55
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

int m, n;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        if (n % (m + 1) == 0)
        {
            printf("Rabbit\n");
        }
        else
        {
            printf("Grass\n");
        }
    }
    return 0;
}
