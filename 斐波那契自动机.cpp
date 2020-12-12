/*
 * @Autor: Whx
 * @Date: 2020-11-08 17:23:50
 * @LastEditTime: 2020-11-08 18:05:32
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 998244353;
ll f[100005];
int n, T, a, b;
char s1[100005], s2[100005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        memset(f, 0, sizeof(f));
        cin >> n >> a >> b;
        cin >> s1;
        cin >> s2;
        int k = 0;
        for (int i = 0; i < a; i++)
        {
            if (s1[i] == '1')
                k++;
            else
            {
                if (k)
                {
                    f[1] += (k - 1);
                    k = 0;
                }
            }
        }
        if (k > 0)
            f[1] += (k - 1);
        f[1] = max(0ll, f[1]);
        k = 0;
        for (int i = 0; i < b; i++)
        {
            if (s2[i] == '1')
                k++;
            else
            {
                if (k)
                {
                    f[2] += (k - 1);
                    k = 0;
                }
            }
        }
        if (k > 0)
            f[2] += (k - 1);
        f[2] = max(0ll, f[2]);
        if (s1[a - 1] == '1' && s2[0] == '1')
            f[3] = (f[1] + f[2] + 1) % mod;
        else
            f[3] = (f[1] + f[2]) % mod;
        for (int i = 4; i <= n; i++)
        {
            if (i & 1)
            {
                if (s2[b - 1] == '1' && s2[0] == '1')
                    f[i] = (f[i - 1] + f[i - 2] + 1) % mod;
                else
                    f[i] = (f[i - 1] + f[i - 2]) % mod;
            }
            else
            {
                if (s2[b - 1] == '1' && s1[0] == '1')
                    f[i] = (f[i - 1] + f[i - 2] + 1) % mod;
                else
                    f[i] = (f[i - 1] + f[i - 2]) % mod;
            }
        }
        // for (int i = 1; i <= n; i++)
        //     cout << f[i] << endl;
        cout << f[n] << endl;
    }
    return 0;
}