/*
 * @Author: Whx
 * @Date: 2020-12-16 19:26:05
 * @LastEditTime: 2021-01-13 10:33:43
 */
/*
只要除了数目最多的糖果以外的其他所有糖果的数目之和加1（小心这里要用int64），
大于等于数目最多的糖果数，就能吃完，否则不能。

原理：O X O M O,三种糖果，
假设其他糖果总数为n
用最多的糖果对其他糖果进行插空最多需要n+1个
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int t, n, k, max_n;
	long long sum;
	cin >> t;
	while (scanf("%d", &n) != EOF)
	{
		sum = max_n = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &k);
			sum += k;
			max_n = max(max_n, k);
		}
		if (sum - max_n + 1 >= max_n)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}