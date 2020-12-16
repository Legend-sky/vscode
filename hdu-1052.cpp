#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, tian[1005], qi[1005], ans;
bool cmp(int a, int b)
{
	return a < b;
}
int main()
{
	ios::sync_with_stdio(!cin.tie(NULL));
	while (cin >> n && n)
	{
		ans = 0;
		for (int i = 0; i < n; i++) cin >> tian[i];
		for (int i = 0; i < n; i++) cin >> qi[i];
		sort(tian, tian + n, cmp);
		sort(qi, qi + n, cmp);
		int i = 0, j = n - 1;
		int p = 0, q = n - 1;
		for (int k = 0; k < n; k++)
		{
			if (tian[i] > qi[p])	//������������������������죬������
			{
				i++;
				p++;
				ans++;
			}
			else if (tian[i] < qi[p])	//����������������������������������������������
			{
				i++;
				q--;
				ans--;
			}
			else		//������������������������һ��
			{
				if (tian[j] > qi[q])	//�����������������������죬�ȿ���
				{
					j--;
					q--;
					ans++;
				}
				else if (tian[i] < qi[q])	//�������������������������������ȣ�����ɵ��������Ŀ���
				{
					i++;
					q--;
					ans--;
				}
			}
		}
		cout << ans * 200 << endl;
	}
	return 0;
}