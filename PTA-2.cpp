/*
 * @Author: Whx
 * @Date: 2021-01-01 19:25:46
 * @LastEditTime: 2021-01-01 19:45:46
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
    int n;
    scanf("%d", &n);
    if (n <= 5750)
    {
        printf("10");
    }
    if (n > 5750 && n <= 13750)
    {
        printf("9");
    }
    if (n > 13750 && n <= 21750)
    {
        printf("8");
    }
    if (n > 21750 && n <= 29750)
    {
        printf("7");
    }
    if (n > 29750 && n <= 77750)
    {
        int t = n - 29750;
        if (t > 0 && t <= 8000)
        {
            printf("6");
        }
        if (t > 8000 && t <= 16000)
        {
            printf("5");
        }
        if (t > 16000 && t <= 24000)
        {
            printf("4");
        }
        if (t > 24000 && t <= 32000)
        {
            printf("3");
        }
        if (t > 32000 && t <= 40000)
        {
            printf("2");
        }
        if (t > 40000 && t <= 48000)
        {
            printf("1");
        }
    }
    if (n > 77750)
    {
        printf("0");
    }
    return 0;
}
