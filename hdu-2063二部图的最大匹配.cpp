/*
 * @Author: Whx
 * @Date: 2020-12-16 19:26:05
 * @LastEditTime: 2020-12-17 23:07:04
 */
// #include<iostream>
// #include<cstring>
// #include<algorithm>
// using namespace std;
// int line[510][510], boy[510], flag[510];	//line表示关系，boy表示女伴,flag表示男生是否被询问过
// int n, m;			//m：女生人数 n：男生人数
// int find(int x)		//匈牙利算法
// {
// 	for (int k = 1; k <= n; k++) {
// 		if (line[x][k] == 1 && flag[k] == 0) {		//若两人之间有关系且在这次查找中没有被询问
// 			flag[k] = 1;
// 			if (boy[k] == 0 || find(boy[k])) {		//如果该男生没有女伴或者该男生的女伴可以找到其他男生，则匹配成功
// 				boy[k] = x;
// 				return 1;
// 			}
// 		}
// 	}
// 	return 0;
// }
// int main()
// {
// 	int k, i, a, b;
// 	while (cin >> k && k) {
// 		cin >> m >> n;
// 		int count = 0;
// 		memset(boy, 0, sizeof(boy));
// 		memset(line, 0, sizeof(line));
// 		for (i = 1; i <= k; i++) {
// 			cin >> a >> b;
// 			line[a][b] = 1;		//女生a和男生b有关系
// 		}
// 		for (i = 1; i <= m; i++) {		//扫描女生，为她们寻找伴侣
// 			memset(flag, 0, sizeof(flag));
// 			if (find(i))
// 				count++;
// 		}
// 		cout << count << endl;
// 	}
// 	return 0;
// }
#include <cstdio>
#include <algorithm>
#include <cstring>
int line[505][505], vis[505], boy[505]; //boy存储男生的女伴
int n, m, k;
bool find(int x)
{
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i] && line[x][i] == 1)
		{
			vis[i] = 1;
			if (boy[i] == -1 || find(boy[i]))
			{
				boy[i] = x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	while (scanf("%d", &k), k)
	{
		memset(boy, -1, sizeof(boy));
		memset(line, 0, sizeof(line));
		scanf("%d%d", &m, &n);
		for (int i = 0; i < k; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			line[a][b] = 1;
		}
		int res = 0;
		for (int i = 1; i <= m; i++)
		{
			memset(vis, 0, sizeof(vis));
			if (find(i))
				res++;
		}
		printf("%d\n", res);
	}
}