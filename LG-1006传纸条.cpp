/*
 * @Autor: Whx
 * @Date: 2020-11-13 20:33:36
 * @LastEditTime: 2020-11-13 21:01:08
 */
#include <bits/stdc++.h>
using namespace std;
int m, n, f[51][51][51][51], a[51][51];
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                for (int l = 1; l < n; l++)
                {
                    f[i][j][k][l] = max(f[i - 1][j][k - 1][l], max(f[i - 1][j][k][l - 1], max(f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1]))) + a[i][j] + a[k][l];
                    if (i == k && j == l)
                        f[i][j][k][l] -= a[i][j];
                }
            }
        }
    }
    // for (int i = 1; i <= m; i++)
    //     for (int j = 1; j <= n; j++)
    //         for (int k = 1; k <= m; k++)
    //         {
    //             for (int l = 1; l <= n; l++)
    //                 cout << f[i][j][k][l] << " ";
    //             cout << endl;
    //         }
    cout << f[m - 1][n][m][n - 1] << endl;
}