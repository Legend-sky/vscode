/*
 * @Author: Whx
 * @Date: 2020-12-16 19:26:05
 * @LastEditTime: 2020-12-24 08:58:08
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dis[101][101];
int init[101][101];
int b[4] = {0, -1, 0, 1};
int c[4] = {-1, 0, 1, 0};
int n, k;
int dfs(int x, int y)
{
	int res = 0;
	int i, j, nx, ny;
	if (dis[x][y])
		return dis[x][y];
	for (i = 0; i < 4; i++)
	{
		for (j = 1; j <= k; j++)
		{
			nx = x + b[i] * j;
			ny = y + c[i] * j;
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && init[nx][ny] > init[x][y])
				res = max(res, dfs(nx, ny));
		}
	}
	dis[x][y] = res + init[x][y];
	return dis[x][y];
}
int main()
{
	int i, j;
	while (cin >> n >> k && n != -1 && k != -1)
	{
		memset(dis, 0, sizeof(dis));
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				cin >> init[i][j];
		cout << dfs(0, 0) << endl;
	}
}
