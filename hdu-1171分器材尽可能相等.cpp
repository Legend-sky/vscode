#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int lmax = 260000;		//还是数组开小了...
int a[lmax], b[lmax], num[500], v[500], i, j, k, last, last2;
int main()
{
	int n;
	while (cin >> n && n > 0) {
		for (i = 0; i < n; i++)
			cin >> v[i] >> num[i];
		a[0] = 1;
		last = 0;
		for (i = 0; i < n; i++) {
			last2 = last + v[i] * num[i];
			memset(b, 0, sizeof(int) * (last2 + 1));
			for (j = 0; j <= num[i]; j++)
				for (k = 0; k<= last; k++)
					b[k + j * v[i]] += a[k];
			memcpy(a, b, sizeof(int) * (last2 + 1));
			last = last2;
		}
		for (i = last / 2; i >= 0 && a[i] == 0; i--);	//输出两个数尽可能相等，就要从一半开始，不能组成的就往下列举
		cout << last - i << ' ' << i << endl;
	}
	return 0;
}