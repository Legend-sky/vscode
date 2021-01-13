/*
 * @Author: Whx
 * @Date: 2020-12-16 19:26:05
 * @LastEditTime: 2021-01-13 10:24:31
 */
#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n) //f[n] mod 3 之后有规律
	{
		if (n % 8 == 2 || n % 8 == 6)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
