/*
��1����x(1<=x<=n)���̴�a������b,d���Ƶ�c�������������Ҫ�Ĳ���ΪF[x];
��2����a����ʣ�µ�n-x��������b���Ƶ�d����ע����ʱ���ܹ�����c������Ϊc���ϵ������̶���a���ϵ���С��
    Щʱ�ƶ���ʽ�൱����һ�����人ŵ���������������Ҫ�Ĳ���Ϊ2^(n-x)-1��֤�������麺ŵ��һ����
��3����c���ϵ�x��������a,b���Ƶ�d���ϣ����������Ҫ�Ĳ���ΪF[x];
��ʵ�ʸ�����Ĵ�Ӧ��min{2*F[x]+2^(n-x)-1},����0<x<n
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n, m;
	long long res, f[65];
	f[1] = 1;
	f[2] = 3;
	for (int i = 3; i <= 64; i++)
	{
		res = 999999999;
		for (int j = 1; j < i; j++)
			res = min(2 * f[j] + pow(2, i - j) - 1, res * 1.0);
		f[i] = res;
	}
	while (cin >> n)
	{
		cout << f[n] << endl;
	}
	return 0;
}