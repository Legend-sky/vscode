/*
��n-1�������塣
��1����n-1��ͨ��C��A->B����Ҫf[n-1].
��2��������һ���A->C,��Ҫ1��.
��3����n-1��ͨ��A��B->C����Ҫf[n-1].
���Ե��ƹ�ʽΪf[n]=2*f[n-1]+1
f[n]+1=2*f[n-1]+2
(f[n]+1)/(f[n-1]+1)=2
f[n]+1=2^n
����ֱ�ӹ�ʽΪf[n]=2^n-1
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
void move(char ch1, char ch2)
{
	static int count = 1;
	cout << "Step " << count++ << " : " << ch1 << "->" << ch2 << endl;
	return;
}

void hanoi(int n, char a, char b, char c)
{
	if (n == 1) move(a, c);
	else
	{
		hanoi(n - 1, a, c, b);
		move(a, c);
		hanoi(n - 1, b, a, c);
	}
	return;
}
int main()
{
	int n;
	cout << "Input the number of diskes:" << endl;
	cin >> n;
	hanoi(n, 'A', 'B', 'C');
	return 0;
}