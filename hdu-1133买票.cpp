/*���������C(m+n,m)*m!*n!
������������C(m+n,m+1)*m!*n!
��ʽ���,˵ʵ����̫��Ϊɶm+1�͹��ˣ�m+2��m+3ɶ��Ϊɶ���ÿ���*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1000];
int main()
{
	int n, m, i, j, len, carry, temp, num = 1;
	while (cin >> m >> n)
	{
		if (!m && !n) break;
		cout << "Test #" << num++ << ":" << endl;
		if (n > m) cout << 0 << endl;
		else {
			memset(a, 0, sizeof(a));
			a[0] = 1;
			len = 1;
			for (i = 1; i <= m + n; i++) 
			{
				if (i == m + 1) continue;		//��ȥ���������˳�����һ��
				for (j = 0; j < len; j++)
					a[j] *= i;
				carry = 0;
				for (j = 0; j < len; j++)
				{
					temp = a[j] + carry;
					a[j] = temp % 10;
					carry = temp / 10;
				}
				while (carry)
				{
					a[len++] = carry % 10;
					carry /= 10;
				}
			}
			if (n) {
				carry = 0;
				for (j = 0; j < len; j++)
					a[j] *= (m - n + 1);
				carry = 0;
				for (j = 0; j < len; j++)
				{
					temp = a[j] + carry;
					a[j] = temp % 10;
					carry = temp / 10;
				}
				while (carry)
				{
					a[len++] = carry % 10;
					carry /= 10;
				}
			}
			for (i = len - 1; i >= 0; i--)
				cout << a[i];
			cout << endl;
		}
	}
	return 0;
}