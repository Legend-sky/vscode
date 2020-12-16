#include<cstdio>
#include<iostream>
#include<cstring>
#define INF 9999999
using namespace std;
char map[110][110];
int turn[110][110];
int dir[4][2] = { 0,-1,0,1,1,0,-1,0 };
int t, n, m, mark, k, sx, sy, ex, ey;
void dfs(int x, int y, int co)
{
	if (x == ex && y == ey && turn[x][y] <= k)
	{
		mark = 1;
		return;
	}
	if (mark) return;
	if (turn[x][y] > k) return;
	if (x != ex && y != ey && turn[x][y] == k) return;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (turn[nx][ny] < turn[x][y]) continue;
		if (co != -1 && co != i && turn[nx][ny] < turn[x][y] + 1) continue;
		if (nx > n || ny > m || nx <= 0 || ny <= 0 || map[nx][ny] == '*') continue;
		map[nx][ny] = '*';
		if (co != -1 && co != i) turn[nx][ny] = turn[x][y] + 1;
		else turn[nx][ny] = turn[x][y];
		dfs(nx, ny, i);
		map[nx][ny] = '.';
	}
}
int main()
{
	cin >> t;
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				scanf(" %c", &map[i][j]);
		}
		scanf("%d%d%d%d%d", &k, &sy, &sx, &ey, &ex);
		memset(turn, INF, sizeof(turn));
		mark = 0;
		turn[sx][sy] = 0;
		dfs(sx, sy, -1);
		if (mark) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}