/*
 * @Author: Whx
 * @Date: 2021-01-01 16:24:26
 * @LastEditTime: 2021-01-01 16:33:27
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

int n, m;
int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0)
            break;
        if ((n % 2) && (m % 2))
        {
            printf("What a pity!\n");
        }
        else
        {
            printf("Wonderful!\n");
        }
    }
    return 0;
}
