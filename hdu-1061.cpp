/*
 * @Author: Whx
 * @Date: 2020-12-16 19:26:05
 * @LastEditTime: 2021-01-13 10:10:19
 */
#include <iostream>
using namespace std;
int main()
{
	int n, a, res;
	int array[10][4] = {{0}, {1}, {6, -1, 4, -1}, {-1, 3, -1, 7}, {6}, {5}, {6}, {-1, 7, -1, 3}, {6, -1, 4, -1}, {9}};
	cin >> n;
	while (n--)
	{
		cin >> a;
		res = a % 10;
		if (res == 0 || res == 1 || res == 4 || res == 5 || res == 6 || res == 9)
		{
			cout << array[res][0] << endl;
		}
		else if (res == 2 || res == 8)
		{
			cout << array[res][a % 4] << endl;
		}
		else if (res == 3 || res == 7)
		{
			cout << array[res][a % 4] << endl;
		}
	}
}
