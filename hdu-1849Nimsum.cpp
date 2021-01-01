/*
 * @Author: Whx
 * @Date: 2020-12-31 16:52:15
 * @LastEditTime: 2021-01-01 16:49:30
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int m, k, res;
    while (scanf("%d", &m) != EOF, m)
    {
        res = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &k);
            res = res ^ k;
        }
        if (res == 0)
        {
            printf("Grass Win!\n");
        }
        else
        {
            printf("Rabbit Win!\n");
        }
    }
    return 0;
}