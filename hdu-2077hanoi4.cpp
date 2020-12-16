/*
(1)把n-1从A->B,这一步(3^(n-1)-1)/2,前一次的三倍加一,递推
(2)把最大的那块从A->C,需要2步
(3)把n-1从B->C,需要的步数和(1)一样
所以f[n]=3^(n-1)+1
递推公式为f[n]=3*f[n-1]-2
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