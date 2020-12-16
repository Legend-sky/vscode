#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int N;
char maze[13][13][13];
int check(int x, int y, int z) {
	if (x >= N || x < 0 || y >= N || y < 0 || z >= N || z < 0)
		return 0;
	return 1;
}
struct node {
	int x, y, z;
	int step;
};
void bfs(int x, int y, int z, int x1, int y1, int z1) {
	if (x == x1 && y == y1 && z == z1) {
		cout << N << " 0" << endl;
		return;
	}
	queue<node> q;
	node head, end;
	head.x = x; head.y = y; head.z = z;
	head.step = 0;
	maze[head.x][head.y][head.z] = 'X';
	q.push(head);
	while (!q.empty()) {
		head = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			memcpy(&end, &head, sizeof(node));
			if (i == 0) end.x = head.x + 1;
			else if (i == 1) end.x = head.x - 1;
			else if (i == 2) end.y = head.y + 1;
			else if (i == 3) end.y = head.y - 1;
			else if (i == 4) end.z = head.z + 1;
			else if (i == 5) end.z = head.z - 1;
			if (maze[end.x][end.y][end.z] != 'X' && check(end.x, end.y, end.z)) {
				maze[end.x][end.y][end.z] = 'X';
				end.step = head.step + 1;
				q.push(end);
				if (end.x == x1 && end.y == y1 && end.z == z1) {
					cout << N << ' ' << end.step << endl;
					return;
				}
			}
		}
	}
	cout << "NO ROUTE" << endl;
	return;
}
int main()
{
	int x, y, z, x1, y1, z1;
	char c[10];
	while (cin >> c) {
		cin >> N;
		memset(maze, '\0', sizeof(maze));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++)
					cin >> maze[i][j][k];
			}
		cin >> x >> y >> z >> x1 >> y1 >> z1;
		cin >> c;
		bfs(z, x, y, z1, x1, y1);
	}
}