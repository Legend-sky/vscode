#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long f(int j, int n)		//��n����ѡ��j������j�����ţ�������˾���j���´�ķ�����
{
	long long a[100] = { 0,0,1,2 }, flag = 1, flag2 = 1;
	for (int i = 3; i <= j; i++)
		a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
	for (int i = 1; i <= j; i++)
		flag *= (n - i + 1);
	for (int i = 1; i <= j; i++)
		flag2 *= i;
	flag /= flag2;
	return (a[j] * flag);
}
int main()
{
	int n;
	long long res;
	while (cin >> n && n)
	{
		res = 0;
		for (int i = 1; i <= n / 2; i++)
			res += f(i, n);
		cout << res + 1 << endl;	//1��ȫ�¶Ե����
	}
	return 0;
}