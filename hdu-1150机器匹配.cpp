/*
 * @Author: Whx
 * @Date: 2020-08-08 11:19:27
 * @LastEditTime: 2020-12-16 22:37:15
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool vis[110], map[110][110]; //map表示所有关系
int line[110];				  //表示两机器之间的连线关系，最大匹配的关系
int n, m, k;
bool dfs(int u)
{
	for (int i = 1; i < m; i++)
	{ //扫描b与a是否有关系
		if (!vis[i] && map[u][i])
		{ //有关系且没被拜访过
			vis[i] = true;
			if (line[i] == -1 || dfs(line[i]))
			{ //机器b还没有牵线或者有其他可以牵线的对象
				line[i] = u;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	while (cin >> n && n)
	{
		cin >> m >> k;
		memset(line, -1, sizeof(line));
		memset(map, false, sizeof(map));
		for (int i = 1; i <= k; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			if (b == 0 || c == 0)
				continue;	  //机器A和B刚开始就是模式0，如果是模式0就不用切换
			map[b][c] = true; //标记关系
		}
		int res = 0;
		for (int i = 1; i < n; i++)
		{
			memset(vis, false, sizeof(vis));
			if (dfs(i))
				res++;
		}
		cout << res << endl;
	}
	return 0;
}

//上课的代码
/*
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MaxN = 510;
int uN, vN;		   //uN是匹配左边的顶点数，vN是匹配右边的顶点数
int g[MaxN][MaxN]; //邻接矩阵
int linker[MaxN];
bool used[MaxN];
bool dfs(int u)
{
	for (int v = 0; v < vN; v++) //从0开始和从1开始并不影响结果
	{
		if (g[u][v] && !used[v])
		{
			used[v] = 1;
			if (linker[v] == -1 || dfs(linker[v])) //linker[v]女生的现男友还可以找到其他的匹配
			{
				linker[v] = u;
				return 1;
			}
		}
	}
	return 0;
}
int solve()
{
	int res = 0;
	memset(linker, -1, sizeof(linker));
	for (int u = 0; u < uN; u++)
	{
		memset(used, 0, sizeof(used)); //每次匹配完成一对都初始化，后面可能要拆开
		if (dfs(u))
			res++;
	}
	return res;
}
int main()
{
	int k;
	while (scanf("%d", &uN) == 1 && uN)
	{
		scanf("%d%d", &vN, &k);
		memset(g, 0, sizeof(g));
		int id, u, v;
		while (k--)
		{
			scanf("%d%d%d", &id, &u, &v);
			if (u != 0 && v != 0)
			{
				g[u][v] = 1;
			}
		}
		printf("%d\n", solve());
	}
	return 0;
}
*/