/*
 * @Author: Whx
 * @Date: 2020-11-22 17:30:36
 * @LastEditTime: 2020-11-23 20:08:44
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
int f[10005], v[10005], w[10005];
int main()
{
    int n, m, E, F, c, d, i, j, t;
    while (cin >> t)
    {
        while (t--)
        {
            memset(f, 0x3f3f3f3f, sizeof(f));
            f[0] = 0;
            cin >> E >> F;
            c = F - E;
            cin >> n;
            for (i = 0; i < n; i++)
            {
                cin >> v[i] >> w[i];
                for (j = w[i]; j <= c; j++)
                    f[j] = min(f[j - w[i]] + v[i], f[j]);
            }
            if (f[c] != 0x3f3f3f3f)
                cout << "The minimum amount of money in the piggy-bank is " << f[c] << "." << endl;
            else
                cout << "This is impossible." << endl;
        }
    }
    return 0;
}