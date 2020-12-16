#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	long long h[34], l[34];
	h[0] = 1; l[0] = 0;
	for (int i = 1; i <= 33; i++)
	{
		h[i] = h[i - 1] * 3 + l[i - 1] * 2;
		l[i] = h[i - 1] + l[i - 1];
	}
	int n;
	while (cin >> n && n != -1)
	{
		cout << h[n] << ", " << l[n] << endl;
	}
	return 0;
}