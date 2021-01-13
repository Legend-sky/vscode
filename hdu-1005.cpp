/*
 * @Author: Whx
 * @Date: 2020-12-16 19:26:05
 * @LastEditTime: 2021-01-13 10:28:03
 */
#include <iostream>
using namespace std;
int main()
{
	int i, j, flag, begin, end, a, b, f[51];
	long n;
	f[1] = f[2] = 1;
	while (cin >> a >> b >> n && (a || b || n))
	{
		flag = 1;
		for (i = 3; i <= n && flag; i++) //  0~6，最多循环14次之后就会出现规律
		{
			f[i] = (a * f[i - 1] + b * f[i - 2]) % 7;
			for (j = 2; j < i; j++)
			{
				if (f[i] == f[j] && f[i - 1] == f[j - 1]) //有两个数相同，后面就会出现规律
				{
					begin = j;
					end = i;
					flag = 0;
					break;
				}
			}
		}
		if (flag)
			cout << f[n] << endl;
		else
			cout << f[begin + (n - end) % (end - begin)] << endl;
	}
	return 0;
}
