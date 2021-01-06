/*
 * @Author: Whx
 * @Date: 2021-01-01 19:49:41
 * @LastEditTime: 2021-01-01 19:55:02
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
    int sh[6][6];
    int ke[6][6];
    memset(sh, 0, sizeof(sh));
    memset(ke, 0, sizeof(ke));
    sh[2][4] = 1;
    sh[4][5] = 1;
    sh[5][1] = 1;
    sh[1][3] = 1;
    sh[3][2] = 1;
    ke[1][2] = 1;
    ke[2][5] = 1;
    ke[5][3] = 1;
    ke[3][4] = 1;
    ke[4][1] = 1;
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (sh[a][b])
        {
            printf("%d sheng %d\n", a, b);
        }
        if (sh[b][a])
        {
            printf("%d sheng %d\n", b, a);
        }
        if (ke[a][b])
        {
            printf("%d ke %d\n", a, b);
        }
        if (ke[b][a])
        {
            printf("%d ke %d\n", b, a);
        }
    }
    return 0;
}
