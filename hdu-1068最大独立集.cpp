/*二分图最大独立集=节点数-最大匹配数，这题中只有一个集合，所以最大匹配数有重复，要除以2*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1000;
int map[N][N], vis[N], line[N];
int n;
int find(int u)
{
	int i;
	for (i = 0; i < n; i++) {
		if (!vis[i] && map[u][i] == 1) {
			vis[i] = 1;
			if (line[i] == -1 || find(line[i])) {
				line[i] = u;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int i, j, k, m, r;
	char c, s, q;
	while (cin >> n) {
		memset(map, 0, sizeof(map));
		memset(line, -1, sizeof(line));
		for (i = 0; i < n; i++) {
			cin >> m >> c >> s >> k >> q;
			for (j = 0; j < k; j++) {
				cin >> r;
				map[m][r] = 1;
			}
		}
		int sum = 0;
		for (i = 0; i < n; i++) {
			memset(vis, 0, sizeof(vis));
			if (find(i)) sum++;
		}
		cout << n - sum / 2 << endl;
	}
	return 0;
}