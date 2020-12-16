#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 150
using namespace std;
int map[maxn][maxn], line[maxn], vis[maxn];
int n, m;
int find(int u)
{
	int i;
	for (i = 1; i <= n; i++) {
		if (!vis[i] && map[u][i]) {
			vis[i] = 1;
			if (line[i] == 0 || find(line[i])) {
				line[i] = u;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int t, i, j, sum, x, y;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(map, 0, sizeof(map));
		memset(line, 0, sizeof(line));
		while (m--) {
			cin >> x >> y;
			map[x][y] = 1;
		}
		sum = 0;
		for (i = 1; i <= n; i++) {
			memset(vis, 0, sizeof(vis));
			if (find(i)) sum++;
		}
		cout << n - sum << endl;
	}
	return 0;
}
