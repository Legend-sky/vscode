/*
把n-1看成整体。
（1）把n-1块通过C从A->B，需要f[n-1].
（2）把最大的一块从A->C,需要1步.
（3）把n-1块通过A从B->C，需要f[n-1].
所以递推公式为f[n]=2*f[n-1]+1
f[n]+1=2*f[n-1]+2
(f[n]+1)/(f[n-1]+1)=2
f[n]+1=2^n
所以直接公式为f[n]=2^n-1
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