#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[105][1000];
int b[1000];
void catalan_factorial()
{
	int i, j, len, carry, temp;
	a[1][0] = b[1] = 1;
	len = 1;
	for (i = 2; i <= 100; i++)
	{
		for (j = 0; j < len; j++)
			a[i][j] = a[i - 1][j] * (4 * i * i - 2 * i);
		carry = 0;
		for (j = 0; j < len; j++)
		{
			temp = a[i][j] + carry;
			a[i][j] = temp % 10;
			carry = temp / 10;
		}
		while (carry)
		{
			a[i][len++] = carry % 10;
			carry /= 10;
		}
		carry = 0;
		for (j = len - 1; j >= 0; j--)
		{
			temp = carry * 10 + a[i][j];
			a[i][j] = temp / (i + 1);
			carry = temp % (i + 1);
		}
		while (!a[i][len - 1])
			len--;
		b[i] = len;
	}
}
int main()
{
	int n, i;
	while (cin >> n && n)
	{
		catalan_factorial();
		for (i = b[n] - 1; i >= 0; i--)
			cout << a[n][i];
		cout << endl;
	}
	return 0;
}