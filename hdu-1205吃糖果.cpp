/*�������-�δ��<=1����ô����϶��н⣺
���ǿ��Դ����ʹδ�����ÿ����һ����Ȼ������Ǻ͵��������ȵ�ʱ��
��ÿ�δ������������һ���������Ǻ͵��Ĵ����ȵ�ʱ��
��ÿ�δ��Ķ��������һ��������һֱ�������жѡ�
���������ܲ���ʹ������-�δ��<=1������֮ǰ���ǻ�Ӵδ��֮�����Щ������ȡ��
�������Ѽ��٣�����ܼ���������-�δ��<=1����ôԭ�����н⡣
�ܷ����Ҫ����
sum - max - max2 >= max - max2 - 1
�Ƿ����������sumΪ�ܺͣ�maxΪ���ѣ�max2Ϊ�δ�
����ã�
2 * sum - max >= max - 1
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t, n, k, maxn;
	long long sum;
	cin >> t;
	while (scanf("%d", &n) != EOF)
	{
		sum = maxn = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &k);
			sum += k;
			maxn = max(maxn, k);
		}
		if (sum - maxn + 1 >= maxn) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}