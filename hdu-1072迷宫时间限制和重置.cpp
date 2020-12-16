#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int map[10][10];
int n, m, s_x, s_y;
int dir[4][2] = { 0,-1,-1,0,0,1,1,0 };
struct node {
	int x, y, etime, step;
};
int check(node t)
{
	if (t.x<0 || t.x>n || t.y<0 || t.y>m || map[t.x][t.y] == 0)
		return 0;
	return 1;
}
int bfs()
{
	queue<node>q;
	node pr, ne;
	int i;
	pr.x = s_x;
	pr.y = s_y;
	pr.etime = 6;
	pr.step = 0;
	q.push(pr);
	while (!q.empty()) {
		pr = q.front();
		q.pop();
		if (map[pr.x][pr.y] == 3)
			return pr.step;
		if (pr.etime == 1)
			continue;
		for (i = 0; i < 4; i++) {
			ne.x = pr.x + dir[i][0];
			ne.y = pr.y + dir[i][1];
			if (!check(ne)) continue;
			ne.etime = pr.etime - 1;
			ne.step = pr.step + 1;
			if (map[ne.x][ne.y] == 4) {
				ne.etime = 6;
				map[ne.x][ne.y] = 0;
			}
			q.push(ne);
		}
	}
	return -1;
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
				if (map[i][j] == 2) {
					s_x = i;
					s_y = j;
				}
			}
		}
		int res = bfs();
		cout << res << endl;
	}
	return 0;
}