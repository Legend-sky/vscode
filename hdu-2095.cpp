#include<stdio.h>
#include<algorithm>
int main()		//�����,��ͬ���������ͱ��0,����ֻʣ�������ε�����
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