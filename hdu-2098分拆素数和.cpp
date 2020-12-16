#include<iostream>
#include<algorithm>
using namespace std;
int isprime(int x)
{
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0) return 0;
	}
	return 1;
}
int main()
{
	int n, res;
	while (cin >> n && n)
	{
		res = 0;
		for (int i = 2; i < n / 2; i++)
			if (isprime(i) && isprime(n - i)) res++;
		cout << res << endl;
	}
	return 0;
}