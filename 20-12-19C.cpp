/*
 * @Author: Whx
 * @Date: 2020-12-19 18:31:36
 * @LastEditTime: 2020-12-20 14:31:19
 */
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

int n, m;
ll a[N];

ll gcd(ll a, ll b) //最大公约数的辗转相除法
{
    if (b == 0)
        return a;
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}
inline void solve()
{
    scanf("%d%d", &n, &m);
    ll g = 0, x;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i < n; i++)
    {
        g = gcd(g, abs(a[i] - a[i - 1])); //gcd(x,y)=gcd(x-y,y)
        //a[]为升序排序序列，否则要加abs
        //gcd(a1+bj,a2+bj,a3+bj,a4+bj,...,an+bj)=gcd(a1+bj,a2-a1,a3-a1,a4-a1,...,an-a1);
        //令g=gcd(a2-a1,a3-a1,a4-a1,...,an-a1)
        //gcd(a1+bj,a2+bj,a3+bj,a4+bj,...,an+bj)=gcd(g,a1+bj)
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%lld", &x);
        printf("%lld ", gcd(g, x + a[0]));
    }
}
int main()
{
    solve();
    return 0;
}
