#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()		//����Ǳ��ӵ���
{
	int n, m, c, t, f;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		f = 101;
		for (int i = 0; i < n; i++)
		{
			cin >> c;
			if (c < f) f = c;
		}
		cout << (100 - f) * (100 - f) << endl;
	}
	return 0;
}