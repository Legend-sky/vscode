#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1000010;
int m, n;
int num[N];		//���ȳ���һ��������鲻�ܶ����ں����ڲ����������ջ���
int dp[N];		//dp[j]�洢��num[j]��β��ǰj�����У��ֳ�i�ε����ֵ
int pre[N];		//pre[j]�洢ǰj�����У���һ����num[j]��β�����ֳ�i�ε����ֵ
int main()
{
	int i, j, sum;
	while (cin >> m >> n) {
		for (i = 1; i <= n; i++)
			cin >> num[i];
		memset(dp, 0, sizeof(dp));
		memset(pre, 0, sizeof(pre));
		for (i = 1; i <= m; i++) {		//���ѭ�����м���
			sum = INT_MIN;
			for (j = i; j <= n; j++) {		//�ڲ�ѭ�������
				dp[j] = max(dp[j - 1], pre[j - 1]) + num[j];
				pre[j - 1] = sum;
				sum = max(sum, dp[j]);
			}
		}
		cout << sum << endl;
	}
}