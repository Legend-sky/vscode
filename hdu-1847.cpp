/*
 * @Author: Whx
 * @Date: 2020-12-30 16:04:17
 * @LastEditTime: 2020-12-30 16:52:25
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n % 3 == 0)
        {
            printf("Cici\n");
        }
        else
        {
            printf("Kiki\n");
        }
    }
    return 0;
}