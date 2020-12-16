#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n, t = 0;
	char a, b;
	while (cin >> n >> a >> b)
	{
		if (t) cout << endl;
		if (n == 1)
		{
			cout << a << endl;
			continue;
		}
		if ((n + 1) % 4 != 0) swap(a, b);	//×îÍâ²ãÊÇa
		int flag = -1, num = 0;
		for (int i = 0; i < n; i++)
		{
			if (i == 0 || i == n - 1)
			{
				cout << ' ';
				for (int j = 1; j <= n - 2; j++)
					cout << b;
				cout << ' ' << endl;
				continue;
			}
			if (i <= n / 2) num = i;
			else num = n - i - 1;
			for (int j = 0; j < n; j++)
			{
				if (j <= num || j >= n - num) flag = -flag;
				if (flag == 1) cout << b;
				else if (flag == -1) cout << a;
			}
			cout << endl;
			flag = -1;
		}
		t++;
	}
	return 0;
}