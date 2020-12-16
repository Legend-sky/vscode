/*
(1)��n-1��A->B,��һ��(3^(n-1)-1)/2,ǰһ�ε�������һ,����
(2)�������ǿ��A->C,��Ҫ2��
(3)��n-1��B->C,��Ҫ�Ĳ�����(1)һ��
����f[n]=3^(n-1)+1
���ƹ�ʽΪf[n]=3*f[n-1]-2
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long f[25];
	f[1] = 2;
	for (int i = 2; i <= 20; i++)
		f[i] = 3 * f[i - 1] - 2;
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << f[n] << endl;
	}
	return 0;
}