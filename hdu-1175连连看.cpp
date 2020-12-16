#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 9999999
using namespace std;
int map[1005][1005];
int vis[1005][1005];
int turn[1005][1005];
int n, m, q, sx, sy, ex, ey, mark, k = 2;
int dir[4][2] = { 0,1,0,-1,-1,0,1,0 };
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
		int nextx = x + dir[i][0];
		int nexty = y + dir[i][1];
		if (turn[nextx][nexty] < turn[x][y]) continue;
		if (co != -1 && co != i && turn[nextx][nexty] < turn[x][y] + 1) continue;	//和上次移动方向不同，说明要转向了
		if (nextx > n || nexty > m || nextx <= 0 || nexty <= 0 || vis[nextx][nexty] || map[nextx][nexty]) continue;
		if (co != -1 && co != i) turn[nextx][nexty] = turn[x][y] + 1;
		else turn[nextx][nexty] = turn[x][y];
		vis[nextx][nexty] = 1;
		dfs(nextx, nexty, i);
		vis[nextx][nexty] = 0;
	}
}
int main()
{
	while (scanf("%d%d", &n, &m) == 2 && n && m)
	{
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				scanf("%d", &map[i][j]);
		}
		cin >> q;
		while (q--)
		{
			memset(turn, INF, sizeof(turn));
			scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
			if (map[sx][sy] != map[ex][ey] || !map[sx][sy] || !map[ex][ey])
			{
				cout << "NO\n";
				continue;
			}
			turn[sx][sy] = 0;
			int temp = map[ex][ey];
			map[ex][ey] = 0;
			mark = 0;
			dfs(sx, sy, -1);
			if (mark) cout << "YES\n";
			else cout << "NO\n";
			map[ex][ey] = temp;
		}
	}
	return 0;
}