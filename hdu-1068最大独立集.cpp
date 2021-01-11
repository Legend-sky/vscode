/*
 * @Author: Whx
 * @Date: 2020-12-16 19:26:05
 * @LastEditTime: 2021-01-06 21:30:19
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int map[501][501];
int vis[501];
int match[501];
int n;
int find(int x) //匈牙利算法
{
	for (int i = 0; i < n; i++)
	{
		if (vis[i] == 0 && map[x][i] == 1)
		{
			vis[i] = 1;
			if (match[i] == -1 || find(match[i]))
			{
				match[i] = x;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		memset(map, 0, sizeof(map));
		memset(match, -1, sizeof(match));
		for (int i = 0; i < n; i++)
		{
			int x, y, q;
			scanf("%d: (%d)", &x, &q);
			for (int j = 0; j < q; j++)
			{
				scanf("%d", &y);
				map[x][y] = 1;
			}
		}
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			memset(vis, 0, sizeof(vis));
			if (find(i))
				sum++;
		}
		printf("%d\n", n - sum / 2); //能匹配的人数中去掉一半，另外一半也匹配不了
	}
}
