/*
�м��ְڷ�,һ������3��,n������3^n����
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long f[35];
	f[1] = 3;
	for (int i = 2; i <= 30; i++)
		f[i] = 3 * f[i - 1];
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