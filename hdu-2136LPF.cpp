/*
 * @Author: Whx
 * @Date: 2020-12-25 22:43:14
 * @LastEditTime: 2020-12-25 23:11:05
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e6 + 5;
int lpf[N];
int main()
{
    memset(lpf, 0, sizeof(lpf)); //本题求的是一个数的最大素数因子在全体素数中的位置
    //素数筛选法
    int k = 1;
    for (int i = 2; i <= N; i++)
    {
        if (lpf[i] == 0) //当i为素数时
        {
            lpf[i] = k;
            for (int j = 2 * i; j <= N; j += i) //将素数i的倍数都标记为不是素数
            {
                lpf[j] = k;
            }
            k++;
        }
    }
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", lpf[n]);
    }
    return 0;
}
