/*
(1)把n-1通过B从A->C,需要f[n-1]
(2)把n从A->B,需要1步
(3)把n-1通过B从C->A,需要f[n-1]
(4)把n从B->C,需要1步
(5)把n-1通过B从A->C,需要f[n-1]
所以递推公式为f[n]=3*f[n-1]+2
直接公式为f[n]=3^n-1
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