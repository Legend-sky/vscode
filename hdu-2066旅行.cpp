#include<iostream>
#include<cstring>
#include<algorithm>
#define INF 9999999
int t, s, d, time, res, n, a, b;
int map[1005][1005];
int vis[1005], dis[1005], start[1005], endn[1005];
using namespace std;
void dijks(int si)
{
	for (int i = 0; i < d; i++) if (si == endn[i]) return;
	for (int i = 1; i <= n; i++)
		if (map[si][i] && dis[i] > dis[si] + map[si][i]) {
			dis[i] = dis[si] + map[si][i];
			dijks(i);
		}
}
int main()
{
	while (cin >> t >> s >> d)
	{
		n = 0;
		res = INF;
		memset(dis, INF, sizeof(dis));
		memset(map, 0, sizeof(map));
		while (t--)
		{
			cin >> a >> b >> time;
			if (time < map[a][b] || !map[a][b])
			{
				map[a][b] = time;
				map[b][a] = time;
			}
			n = max(n, a);
			n = max(n, b);
		}
		res = INF;
		for (int i = 0; i < s; i++) cin >> start[i];
		for (int i = 0; i < d; i++) cin >> endn[i];
		for (int i = 0; i < s; i++) dis[start[i]] = 0;
		for (int i = 0; i < s; i++) dijks(start[i]);
		for (int i = 0; i < d; i++) res = min(res, dis[endn[i]]);
		cout << res << endl;
	}

}