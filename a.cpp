#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m, sx, sy, nx, ny;
int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
char Map[205][205];
int res;
void dfs(int x, int y, int step)
{
	for (int i = 0; i < 4; i++)
	{
		nx = x + dir[i][0];
		ny = y + dir[i][1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
		{
			if (Map[nx][ny] == '#') continue;
			if (Map[nx][ny] == 'x' && step + 2 < res)
			{
				Map[nx][ny] = '#';
				dfs(nx, ny, step + 2);
				Map[nx][ny] = 'x';
			}
			else if (Map[nx][ny] == '.' && step + 1 < res)
			{
				Map[nx][ny] = '#';
				dfs(nx, ny, step + 1);
				Map[nx][ny] = '.';
			}
			else if (Map[nx][ny] == 'r')
			{
				res = min(step + 1, res);
				return;
			}
		}
	}
}
int main()
{
	while (cin >> n >> m) {
		res = 10000;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> Map[i][j];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (Map[i][j] == 'r')
				{
					nx = i;
					ny = j;
				}
				if (Map[i][j] == 'a')
				{
					sx = i;
					sy = j;
				}
			}
		}
		Map[sx][sy] = '#';
		dfs(sx, sy, 0);
		if (res != 10000) cout << res << endl;
		else cout << "Poor ANGEL has to stay in the prison all his life." << endl;
	}
	return 0;
}