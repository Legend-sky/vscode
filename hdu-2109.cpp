#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(!cin.tie(NULL));
	int n, a[105], b[105], awin, bwin;
	while (cin >> n && n)
	{
		awin = bwin = 0;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		sort(a, a + n);
		sort(b, b + n);
		for (int i = 0; i < n; i++)
		{
			if (a[i] > b[i]) awin += 2;
			else if (a[i] == b[i]) { awin++; bwin++; }
			else bwin += 2;
		}
		cout << awin << " vs " << bwin << endl;
	}
	return 0;
}