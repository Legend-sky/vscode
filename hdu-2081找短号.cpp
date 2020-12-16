#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	long long n, m;
	cin >> n;
	while (n--)
	{
		cin >> m;
		m = m % 100000 + 600000;
		cout << m << endl;
	}
	return 0;
}