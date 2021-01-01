/*
 * @Author: Whx
 * @Date: 2020-12-30 16:51:57
 * @LastEditTime: 2021-01-01 16:50:44
 */
/*
mex(S) 的值为集合 S 中没有出现过的最小自然数。
例如，mex({1,2}) = 0、mex({0,1,2,3}) = 4

有1堆n个的石子，每次只能取{ 1, 3, 4 }个石子，先取完石子者胜利
那么各个数的SG值为多少？
SG[0]=0，f[]={1,3,4},
x=1时,可以取走1 - f{1}个石子，剩余{0}个，所以
SG[1] = mex{ SG[0] }= mex{0} = 1;

x=2时,可以取走2 - f{1}个石子，剩余{1}个，所以
SG[2] = mex{ SG[1] }= mex{1} = 0;

x=3时,可以取走3 - f{1,3}个石子，剩余{2,0}个，所以
SG[3] = mex{SG[2],SG[0]} = mex{0,0} =1;

x=4时,可以取走4 - f{1,3,4}个石子，剩余{3,1,0}个，所以
SG[4] = mex{SG[3],SG[1],SG[0]} = mex{1,1,0} = 2;

x=5时,可以取走5 - f{1,3,4}个石子，剩余{4,2,1}个，所以
SG[5] = mex{SG[4],SG[2],SG[1]} =mex{2,0,1} = 3;
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int fib[25];
int sg[1005];
int vis[1005];
void solve()
{
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i <= 20; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for (int i = 0; i <= 1001; i++)
    {
        memset(vis, 0, sizeof(vis));
        for (int j = 1; fib[j] <= i; j++)
        {
            vis[sg[i - fib[j]]] = 1;
        }
        for (int j = 0;; j++)
        {
            if (!vis[j])
            {
                sg[i] = j;
                break;
            }
        }
    }
}
int main()
{
    int m, n, p;
    solve();
    while (~scanf("%d%d%d", &m, &n, &p))
    {
        if (m == 0 && n == 0 && p == 0)
            break;
        if (sg[m] ^ sg[n] ^ sg[p]) //不能用sg[m] ^ sg[n] ^ sg[p]==0，等于运算符优先级比^低......
        {
            printf("Fibo\n");
        }
        else
        {
            printf("Nacci\n");
        }
    }
    return 0;
}