#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n, i, j;
	double l, c, t, vr, vt1, vt2, res, len, p[150], dp[150];
	while (cin >> l) {
		cin >> n >> c >> t;
		cin >> vr >> vt1 >> vt2;
		for (i = 1; i <= n; i++)
			cin >> p[i];
		p[0] = 0;
		p[n + 1] = l;
		dp[0] = 0;
		for (i = 1; i < n + 2; i++) {
			dp[i] = 9999999;
			for (j = 0; j < i; j++) {		//�оٵ�i������վ��ǰ��ÿ������վ֮�����õ�·��ѡȡ��С��
				len = p[i] - p[j];		//ÿվ�������м��ͻ��߲����͵ģ�����ʱ��ܳ�����vt1��vt2����С������Ѿ����ǽ�ȥ��
				if (len > c)
				{
					res = c / vt1 + (len - c) / vt2;
				}
				else
				{
					res = len / vt1;
				}
				res += dp[j];
				if (j) res += t;
				dp[i] = min(dp[i], res);
			}
		}
		if ((l / vr) < dp[n + 1]) cout << "Good job,rabbit!" << endl;
		else cout << "What a pity rabbit!" << endl;
	}
	return 0;
}