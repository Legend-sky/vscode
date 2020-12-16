/*
最大的盘n只能在A和C
当最大的盘子在A的时候，n-1的盘子只能在A或B
当最大的盘子在C的时候，n-1的盘子只能在B或C
*/
#include<iostream>
#include<algorithm>
using namespace std;
int judge(int n, int a[], int b[], int c[])
{
	if (b[0] == n) return  0;
	else if (a[0] == n) return judge(n - 1, a + 1, c, b);	//a上面的n-1通过c到b
	else if (c[0] == n) return judge(n - 1, b, a, c + 1);	//b上面的n-1通过a到c
	return 1;
}
int a[100], b[100], c[100];
int main()
{
	int t, n, m, p, q;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cin >> m;
		for (int i = 0; i < m; i++)
			cin >> a[i];
		cin >> p;
		for (int i = 0; i < p; i++)
			cin >> b[i];
		cin >> q;
		for (int i = 0; i < q; i++)
			cin >> c[i];
		a[m] = b[p] = c[q] = -1;
		if (judge(n, a, b, c)) cout << "true" << endl;
		else cout << "false" << endl;
	}
	return 0;
}