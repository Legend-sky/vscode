/*
 * @Author: Whx
 * @Date: 2020-12-23 21:35:44
 * @LastEditTime: 2020-12-23 21:43:09
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int c1[125], c2[125];
int main()
{
    int n;
    memset(c1, 0, sizeof(c1));
    memset(c2, 0, sizeof(c2));
    for (int i = 0; i < 125; i++)
    {
        c1[i] = 1;
    }
    for (int i = 2; i < 124; i++)
    {
        for (int j = 0; j < 124; j++)
        {
            for (int k = 0; k + j <= 124; k += i)
            {
                c2[j + k] += c1[j];
            }
        }
        for (int j = 0; j < 124; j++)
        {
            c1[j] = c2[j];
            c2[j] = 0;
        }
    }
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", c1[n]);
    }
    return 0;
}