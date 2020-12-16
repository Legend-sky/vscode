#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n, i, j, f = 0;
	char c;
	while (cin >> c && c != '@')
	{
		cin >> n;
		if (f) cout << endl;
		f = 1;
		if (n == 1)
		{
			cout << c << endl;
			continue;
		}
		for (i = 1; i < n; i++) cout << ' ';
		cout << c << endl;
		for (i = 2; i <= n - 1; i++)
		{
			for (j = 1; j <= n - i; j++) cout << ' ';
			cout << c;
			for (j = 1; j <= 2 * i - 3; j++) cout << ' ';
			cout << c << endl;
		}
		for (i = 1; i <= 2 * n - 1; i++) cout << c;
		cout << endl;
	}
	return 0;
}