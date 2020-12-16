#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	char a[1005], b[1005];
	while (cin >> a >> b)
	{
		if (a[0] == '#') break;
		int n1, n2, res = 0;
		n1 = strlen(a);
		n2 = strlen(b);
		for (int i = 0; i < n1; i++)
		{
			if (a[i] == b[0])
			{
				int j, k = i;
				for (j = 1; j < n2; j++)
				{
					if (a[++k] != b[j]) break;
				}
				if (j == n2)
				{
					res++;
					i = k;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}