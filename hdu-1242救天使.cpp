//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int n, m, s_x, s_y, e_x, e_y;
//int res;
//char maze[220][220];
//bool status[220][220];
//int dir[4][2] = { 0,-1,-1,0,0,1,1,0 };
//int check(int x, int y)
//{
//	if (x >= n || x < 0 || y >= m || y < 0)
//		return 0;
//	return 1;
//}
//void dfs(int x, int y, int step)			//一次ac，也算一种成就吧
//{
//	int i, j, n_x, n_y;
//	if (x == e_x && y == e_y) {
//		if (res > step) res = step;
//		return;
//	}
//	status[x][y] = true;
//	for (i = 0; i < 4; i++) {
//		n_x = x + dir[i][0];
//		n_y = y + dir[i][1];
//		if (!status[n_x][n_y] && check(n_x, n_y)) {
//			if (maze[n_x][n_y] == 'x') {
//				dfs(n_x, n_y, step + 2);
//				status[n_x][n_y] = false;
//			}
//			else {
//				dfs(n_x, n_y, step + 1);
//				status[n_x][n_y] = false;
//			}
//		}
//	}
//	return;
//}
//int main()
//{
//	int i, j;
//	while (cin >> n >> m) {
//		res = INT_MAX;
//		memset(maze, '\0', sizeof(maze));
//		memset(status, false, sizeof(status));
//		for (i = 0; i < n; i++) {
//			for (j = 0; j < m; j++) {
//				cin >> maze[i][j];
//				if (maze[i][j] == 'a') {
//					s_x = i;
//					s_y = j;
//					status[i][j] = true;
//				}
//				if (maze[i][j] == 'r') {
//					e_x = i;
//					e_y = j;
//				}
//				if (maze[i][j] == '#')
//					status[i][j] = true;
//			}
//		}
//		dfs(s_x, s_y, 0);
//		if (res != INT_MAX) cout << res << endl;
//		else cout << "Poor ANGEL has to stay in the prison all his life." << endl;
//	}
//	return 0;
//}