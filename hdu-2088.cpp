#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n, hi[105], aver, sum, move, flag = 0;
	while (cin >> n && n)
	{
		sum = move = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &hi[i]);
			sum += hi[i];
		}
		if (flag) printf("\n");
		aver = sum / n;
		for (int i = 0; i < n; i++)
			if (hi[i] - aver > 0) move += (hi[i] - aver);
		cout << move << endl;
		flag++;
	}
	return 0;
}