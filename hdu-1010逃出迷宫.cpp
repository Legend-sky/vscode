#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char maze[10][10];
bool status[10][10];		//����һ��״̬,true��ʾ�߹����߲�����
int n, m, t, f;
int s_x, s_y, e_x, e_y;
int dir[4][2] = { 0,-1,-1,0,0,1,1,0 };
void dfs(int a, int b, int nowt) {
	if (f) return;			//��仰���ӳ�ʱ��������G++296MS,��C++421MS
	if (nowt > t || (nowt == t && (a != e_x || b != e_y))) 
		return;
	if (a == e_x && b == e_y && nowt == t) {
		f = 1;
		return;		//�ҵ�
	}
	if (a < 0 || a >= n || b < 0 || b >= m) 
		return;		//Խ��
	if (t - nowt < abs(e_x - a) + abs(e_y - b))
		return;		//��ʣ���·�����ߵ�·�������ܵ�ʱ��,��֦
	if ((t - nowt) % 2 != (abs(e_x - a) + abs(e_y - b)) % 2)
		return;		//��ż��֦:�����յ�����ʱ�����ż�Ժ͵����յ��·����ż�Բ�ͬ;
	for (int i = 0; i < 4; i++) {
		int nexta = a + dir[i][0];
		int nextb = b + dir[i][1];
		if (!status[nexta][nextb]) {
			status[a][b] = true;
			dfs(nexta, nextb, nowt + 1);
			status[nexta][nextb] = false;		//������Ҫ���˻�����ʱ��Ҫ���˻ص�·���ȥ��
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