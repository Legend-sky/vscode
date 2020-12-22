/*
 * @Author: Whx
 * @Date: 2020-12-19 17:40:47
 * @LastEditTime: 2020-12-19 17:50:21
 */
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

int n;
string a, b;

inline void solve()
{
    a.resize(1005);
    b.resize(1005);
    scanf("%d", &n);
    scanf("%s", &a[0]);
    scanf("%s", &b[0]);
    int Rw = 0, Bw = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
            Rw++;
        if (b[i] > a[i])
            Bw++;
    }
    if (Rw > Bw)
        printf("RED\n");
    else if (Bw > Rw)
        printf("BLUE\n");
    else
        printf("EQUAL\n");
}
int main()
{
    int T = 1;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        solve();
    }
    return 0;
}