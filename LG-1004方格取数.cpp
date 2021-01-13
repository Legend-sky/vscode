/*
 * @Autor: Whx
 * @Date: 2020-11-12 21:37:26
 * @LastEditTime: 2020-11-13 20:43:33
 */
#include <bits/stdc++.h>
using namespace std;
int maze[10][10];
int f[10][10][10][10];
int n, x, y, num;
int main()
{
    cin >> n;
    memset(maze, 0, sizeof(maze));
    while (cin >> x >> y >> num && (x || y || num))
        maze[x][y] = num;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                for (int l = 1; l <= n; l++)
                {
                    f[i][j][k][l] = max(f[i - 1][j][k - 1][l], max(f[i - 1][j][k][l - 1], max(f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1]))) + maze[i][j] + maze[k][l];
                    if (i == k && j == l)
                        f[i][j][k][l] -= maze[i][j];
                }
            }
        }
    }
    cout << f[n][n][n][n];
    return 0;
}