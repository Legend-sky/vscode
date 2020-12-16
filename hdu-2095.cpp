#include<stdio.h>
#include<algorithm>
int main()		//用异或,相同的数字异或就变成0,最终只剩下奇数次的数字
{
	int n;
	while (scanf_s("%d", &n) && n)
	{
		int m;
		scanf_s("%d", &m);
		for (int i = 1; i < n; i++)
		{
			int k;
			scanf_s("%d", &k);
			m ^= k;
		}
		printf("%d\n", m);
	}
	return 0;
}