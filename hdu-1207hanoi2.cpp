/*
（1）将x(1<=x<=n)个盘从a柱依靠b,d柱移到c柱，这个过程需要的步数为F[x];
（2）将a柱上剩下的n-x个盘依靠b柱移到d柱（注：此时不能够依靠c柱，因为c柱上的所有盘都比a柱上的盘小）
    些时移动方式相当于是一个经典汉诺塔，即这个过程需要的步数为2^(n-x)-1（证明见再议汉诺塔一）；
（3）将c柱上的x个盘依靠a,b柱移到d柱上，这个过程需要的步数为F[x];
即实际该问题的答案应该min{2*F[x]+2^(n-x)-1},其中0<x<n
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