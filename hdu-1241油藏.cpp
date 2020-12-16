#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char maze[110][110];
int m, n, res;
int dir[8][2] = { 0,-1,-1,-1,-1,0,-1,1,0,1,1,1,1,0,1,-1 };
int check(int x, int y)
{
	if (x >= m || x < 0 || y >= n || y < 0)
		return 0;
	return 1;
}
void dfs(int x, int y)
{
	int i, j, k;
	int nx, ny;
	maze[x][y] = '.';
	for (i = 0; i < 8; i++) {
		nx = x + dir[i][0];
		ny = y + dir[i][1];
		if (maze[nx][ny] == '@' && check(nx, ny)) {
			dfs(nx, ny);
		}
	}
	return;
}
int main()
{
	int i, j;
	while (cin >> m >> n) {
		if (m == 0 && n == 0)
			return 0;
		res = 0;
		memset(maze, '\0', sizeof(maze));
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				cin >> maze[i][j];
			}
		}
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (maze[i][j] == '@') {
					dfs(i, j);
					res++;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}