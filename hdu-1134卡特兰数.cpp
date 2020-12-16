#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[104][100];	//a[i][j]save the catalan number and i stand for i-th catalan number
int b[100];		//catalan number of digits
void catalan()
{
	int i, j, len, carry, temp;
	a[1][0] = b[1] = 1;
	len = 1;
	for (i = 2; i <= 100; i++)
	{
		for (j = 0; j < len; j++)		//mutiply(4*i-2)
			a[i][j] = a[i - 1][j] * (4 * i - 2);
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
		for (j = len - 1; j >= 0; j--)		//divide(i+1)
		{
			temp = carry * 10 + a[i][j];	//The first digit is ten times the next digit
			a[i][j] = temp / (i + 1);	//and the remaining carry is multiplied by 10 for the next digit
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
	catalan();
	while (cin >> n && n != -1)
	{
		for (i = b[n] - 1; i >= 0; i--)
			cout << a[n][i];
		cout << endl;
	}
	return 0;
}
