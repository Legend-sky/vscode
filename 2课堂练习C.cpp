/*
 * @Author: Whx
 * @Date: 2021-01-06 18:51:58
 * @LastEditTime: 2021-01-06 18:54:29
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
    char str[100];
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", &str);
        int num = 0;
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                num = num * 10 + str[i] - 48;
            }
        }
        printf("%d\n", num * 513);
    }
    return 0;
}
