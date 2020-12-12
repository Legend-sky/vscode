/*
 * @Autor: Whx
 * @Date: 2020-10-23 22:02:24
 * @LastEditTime: 2020-10-23 23:43:41
*/
#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n;

inline void solve()
{
    cin>>n;
    cout<<2<<endl;
    cout<<n-1<<' '<<n<<endl;
    for(int i=n-2;i>=1;--i)
    {
        cout<<i<<' '<<i+2<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    for(int t = 1; t <= T; ++t)
    {
        solve();
    }
    return 0;
}