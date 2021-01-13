/*
 * @Author: Whx
 * @Date: 2021-01-13 16:33:55
 * @LastEditTime: 2021-01-13 16:56:51
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define ll long long

using namespace std;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;
int f[100005];
int find(int x)
{
    if (f[x] == x)
    {
        return f[x];
    }
    else
        return find(f[x]);
}
void merge(int a, int b)
{
    int fa = find(a);
    int fb = find(b);
    f[fb] = fa;
}
int main()
{
    int a, b, sum;
    bool flag;
    while (1)
    {
        flag = 0;
        while (cin >> a >> b && a != 0 && b != 0)
        {
            if (a == -1 && b == -1)
                return 0;
            if (f[a] == 0)
                f[a] = a;
            if (f[b] == 0)
                f[b] = b;
            if (find(a) == find(b)) //如果新加入两个结点都在树中，则会构成环
                flag = 1;
            else if (flag != 1)
                merge(a, b);
        }
        sum = 0;
        for (int i = 1; i <= 100000; i++)
        {
            if (f[i] == i)
                sum++;
            f[i] = 0;
        }
        if (sum > 1 || flag == 1) //首领个数大于一个，说明有多个树，不符合
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}
