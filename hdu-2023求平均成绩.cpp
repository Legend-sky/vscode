#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n,m,a[51][6],i,j,sum,f;
	while(cin >> n >> m)
	{
		double b[51] = {0.0},c[6] = {0.0};
		sum = 0;
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{
				cin >> a[i][j];
				b[i] += a[i][j];
				c[j] += a[i][j];
			}
		}
		for(i = 1; i <= n; i++)
			b[i] /= m;
		for(j = 1; j <= m; j++)
			c[j] /= n;
		cout.setf(ios::fixed);
		cout.precision(2);
		for(i = 1; i < n; i++)
			cout << b[i] << ' ';
		cout << b[n] << endl;
		for(j = 1; j < m; j++)
			cout << c[j] << ' ';
		cout << c[m] << endl;
		for(i = 1; i <= n; i++)
		{
			f = 1;
			for(j = 1; j <= m; j++)
			{
				if(a[i][j] < c[j]){
					f = 0;
					break;
				}
			}
			if(f) sum++;
		}
		cout << sum << endl << endl;
	}
	return 0;
}
