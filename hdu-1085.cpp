/*
 * @Author: Whx
 * @Date: 2020-12-16 19:26:05
 * @LastEditTime: 2021-01-10 19:26:52
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int lmax = 9000;
int a[lmax], b[lmax], num[3], i, j, k, last, last2;
int v[3] = {1, 2, 5};
int main()
{
	while (cin >> num[0] >> num[1] >> num[2])
	{
		if (num[0] + num[1] + num[2] == 0)
			break;
		a[0] = 1;
		last = 0;
		for (i = 0; i <= 2; i++)
		{
			last2 = last + num[i] * v[i];
			memset(b, 0, sizeof(int) * (last2 + 1));
			for (j = 0; j <= num[i]; j++)
			{
				for (k = 0; k <= last; k++)
				{
					b[k + j * v[i]] += a[k];
				}
			}
			memcpy(a, b, sizeof(int) * (last2 + 1));
			last = last2;
		}
		for (i = 0; i <= last; i++)
			if (a[i] == 0)
				break;
		cout << i << endl;
	}
	return 0;
}