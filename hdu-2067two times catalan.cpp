#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int f[50][100], digit[100], len, carry, temp;
void catalan()
{
	memset(f, 0, sizeof(f));
	memset(digit, 0, sizeof(digit));
	f[1][0] = 2;
	len = digit[1] = 1;
	for (int i = 2; i <= 35; i++)
	{
		for (int j = 0; j < len; j++)
			f[i][j] = f[i - 1][j] * (4 * i - 2);
		carry = 0;
		for (int j = 0; j < len; j++)
		{
			temp = f[i][j] + carry;
			f[i][j] = temp % 10;
			carry = temp / 10;
		}
		while (carry)
		{
			f[i][len++] = carry % 10;
			carry /= 10;
		}
		carry = 0;
		for (int j = len - 1; j >= 0; j--)
		{
			temp = carry * 10 + f[i][j];
			f[i][j] = temp / (i + 1);
			carry = temp % (i + 1);
		}
		while (!f[i][len - 1])
			len--;
		digit[i] = len;
	}
}
int main()
{
	int n, num;
	catalan();
	num = 1;
	while (cin >> n && n != -1)
	{
		cout << num++ << ' ' << n << ' ';
		for (int i = digit[n] - 1; i >= 0; i--)
			cout << f[n][i];
		cout << endl;
	}
	return 0;
}