/*
(1)��n-1ͨ��B��A->C,��Ҫf[n-1]
(2)��n��A->B,��Ҫ1��
(3)��n-1ͨ��B��C->A,��Ҫf[n-1]
(4)��n��B->C,��Ҫ1��
(5)��n-1ͨ��B��A->C,��Ҫf[n-1]
���Ե��ƹ�ʽΪf[n]=3*f[n-1]+2
ֱ�ӹ�ʽΪf[n]=3^n-1
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long f[40];
	int n;
	f[1] = 2;
	for (int i = 2; i <= 35; i++)
		f[i] = 3 * f[i - 1] + 2;
	while (cin >> n)
	{
		cout << f[n] << endl;
	}
	return 0;
}