#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int a, b, c;
int maze[60][60][60];
bool used[60][60][60];
int dir[6][3] = { 1,0,0,-1,0,0,0,0,-1,0,-1,0,0,0,1,0,1,0 };
int res;
int limit;		//限制时间
struct node {
	int x, y, z, step;		//z层,x行,y列
};
int check_ach(node t)
{
	if (t.z == a - 1 && t.x == b - 1 && t.y == c - 1)
		return 1;
	return 0;
}
int check_move(node t)
{
	if (t.z < 0 || t.z >= a || t.x < 0 || t.x >= b || t.y < 0 || t.y >= c || used[t.z][t.x][t.y] || maze[t.z][t.x][t.y])
		return 0;
	return 1;
}
int bfs()
{
	queue<node>q;
	node pr, ne;
	memset(used, 0, sizeof(used));
	pr.x = pr.y = pr.z = 0;
	pr.step = 0;
	used[0][0][0] = true;
	q.push(pr);
	while (!q.empty()) {
		pr = q.front();
		q.pop();
		if (check_ach(pr))
			return pr.step;
		if (pr.step + (a - pr.z) + (b - pr.x) + (c - pr.y) > limit)		//时间不够，剪枝
			continue;
		for (int i = 0; i < 6; i++) {
			ne.x = pr.x + dir[i][1];
			ne.y = pr.y + dir[i][2];
			ne.z = pr.z + dir[i][0];
			ne.step = pr.step + 1;
			if (check_move(ne)) {
				used[ne.z][ne.x][ne.y] = true;
				q.push(ne);
			}
		}
	}
	return INT_MAX;
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> limit;
		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				for (int k = 0; k < c; k++)
					scanf_s("%d", &maze[i][j][k]);
		res = bfs();
		if (res <= limit) {
			cout << res << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}
