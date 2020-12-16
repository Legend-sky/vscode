#include<set>
#include<map>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
char c1[35], c2[35], st[35], en[35];
map<string, int> p;
int pic[155][155], dis[155], n, t, cnt;
bool vis[155];
void djikstra()
{
	int k = 1;
	vis[k] = 1;
	dis[k] = 0;
	for (int i = 1; i <= cnt; i++)
		if (!vis[i] && pic[k][i] < dis[i])
			dis[i] = pic[k][i];
	for (int i = 1; i < cnt; i++)
	{
		int m = INF;
		for (int j = 1; j <= cnt; j++)
		{
			if (!vis[j] && dis[j] < m)
			{
				m = dis[j];
				k = j;
			}
		}
		vis[k] = 1;
		for (int j = 1; j <= cnt; j++)
			if (pic[k][j] < INF)
				if (dis[j] > dis[k] + pic[k][j])
					dis[j] = dis[k] + pic[k][j];
	}
}
int main()
{
	while (scanf("%d", &n) != EOF && n != -1)
	{
		if (n == 0)
		{
			printf("0\n");
			continue;
		}
		memset(pic, INF, sizeof(pic));
		memset(dis, INF, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		p.clear();
		cnt = 0;
		scanf("%s %s", st, en);
		p[st] = ++cnt;
		if (!p[en]) p[en] = ++cnt;
		for (int i = 1; i <= n; i++)
		{
			scanf("%s %s %d", c1, c2, &t);
			if (!p[c1]) p[c1] = ++cnt;
			if (!p[c2]) p[c2] = ++cnt;
			if (pic[p[c1]][p[c2]] > t) pic[p[c1]][p[c2]] = pic[p[c2]][p[c1]] = t;
		}
		djikstra();
		if (p[st] == p[en]) printf("0\n");
		else if (dis[p[en]] == INF) printf("-1\n");
		else printf("%d\n", dis[p[en]]);
	}
	return 0;
}