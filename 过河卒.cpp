/*
 * @Autor: Whx
 * @Date: 2020-11-08 20:21:54
 * @LastEditTime: 2020-11-08 21:07:50
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int ma[50][50];
int tx[9] = {-2, -2, -1, -1, 1, 1, 2, 2};
int ty[9] = {-1, 1, -2, 2, -2, 2, -1, 1};
int n, m, horse_x, horse_y;
ll f[25][25];
int main()
{
    cin >> n >> m >> horse_x >> horse_y;
    n += 2;
    m += 2;
    horse_x += 2;
    horse_y += 2;
    memset(ma, 0, sizeof(ma));
    ma[horse_x][horse_y] = 1;
    for (int i = 0; i < 8; i++)
    {
        int t_x = horse_x + tx[i];
        int t_y = horse_y + ty[i];
        if (t_x >= 0 && t_x <= n && t_y >= 0 && t_y <= m)
            ma[t_x][t_y] = 1;
    }
    f[2][2] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!ma[i][j])
                f[i][j] = max(f[i][j], f[i - 1][j] + f[i][j - 1]);
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << f[n][m] << endl;
}