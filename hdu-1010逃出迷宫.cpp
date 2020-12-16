#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char maze[10][10];
bool status[10][10];		//定义一个状态,true表示走过或者不能走
int n, m, t, f;
int s_x, s_y, e_x, e_y;
int dir[4][2] = { 0,-1,-1,0,0,1,1,0 };
void dfs(int a, int b, int nowt) {
	if (f) return;			//这句话不加超时，加了用G++296MS,用C++421MS
	if (nowt > t || (nowt == t && (a != e_x || b != e_y))) 
		return;
	if (a == e_x && b == e_y && nowt == t) {
		f = 1;
		return;		//找到
	}
	if (a < 0 || a >= n || b < 0 || b >= m) 
		return;		//越界
	if (t - nowt < abs(e_x - a) + abs(e_y - b))
		return;		//当剩余的路和已走的路不满足总的时间,剪枝
	if ((t - nowt) % 2 != (abs(e_x - a) + abs(e_y - b)) % 2)
		return;		//奇偶剪枝:到达终点所需时间的奇偶性和到达终点的路程奇偶性不同;
	for (int i = 0; i < 4; i++) {
		int nexta = a + dir[i][0];
		int nextb = b + dir[i][1];
		if (!status[nexta][nextb]) {
			status[a][b] = true;
			dfs(nexta, nextb, nowt + 1);
			status[nexta][nextb] = false;		//这句很重要，退回来的时候要把退回的路算回去。
		}
	}
	return;
}
int main()
{
	while (cin >> n >> m >> t) {
		if (n == 0 && m == 0 && t == 0) break;
		memset(maze, '\0', sizeof(maze));
		memset(status, false, sizeof(status));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> maze[i][j];
				if (maze[i][j] == 'S') {
					s_x = i;
					s_y = j;
					status[i][j] = true;
				}
				if (maze[i][j] == 'D') {
					e_x = i;
					e_y = j;
				}
				if (maze[i][j] == 'X') {
					status[i][j] = true;
				}
			}
		}
		f = 0;
		dfs(s_x, s_y, 0);
		if (f) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}