#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	long long a, b;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		if (a % b == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}