/*
 * @Author: Whx
 * @Date: 2020-08-08 11:19:27
 * @LastEditTime: 2020-12-18 17:22:48
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool vis[110], map[110][110]; //map��ʾ���й�ϵ
int line[110];				  //��ʾ������֮������߹�ϵ�����ƥ��Ĺ�ϵ
int n, m, k;
bool dfs(int u)
{
	for (int i = 1; i < m; i++)
	{ //ɨ��b��a�Ƿ��й�ϵ
		if (!vis[i] && map[u][i])
		{ //�й�ϵ��û���ݷù�
			vis[i] = true;
			if (line[i] == -1 || dfs(line[i]))
			{ //����b��û��ǣ�߻�������������ǣ�ߵĶ���
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
				continue;	  //����A��B�տ�ʼ����ģʽ0�������ģʽ0�Ͳ����л�
			map[b][c] = true; //��ǹ�ϵ
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

//�ϿεĴ���
/*
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MaxN = 510;
int uN, vN;		   //uN��ƥ����ߵĶ�������vN��ƥ���ұߵĶ�����
int g[MaxN][MaxN]; //�ڽӾ���
int linker[MaxN];
bool used[MaxN];
bool dfs(int u)
{
	for (int v = 0; v < vN; v++) //��0��ʼ�ʹ�1��ʼ����Ӱ����
	{
		if (g[u][v] && !used[v])
		{
			used[v] = 1;
			if (linker[v] == -1 || dfs(linker[v])) //linker[v]Ů���������ѻ������ҵ�������ƥ��
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
		memset(used, 0, sizeof(used)); //ÿ��ƥ�����һ�Զ���ʼ�����������Ҫ��
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