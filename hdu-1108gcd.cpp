/*
 * @Author: Whx
 * @Date: 2020-12-16 19:26:05
 * @LastEditTime: 2021-01-13 10:07:54
 */
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << a * b / gcd(a, b) << endl;
	}
	return 0;
}
