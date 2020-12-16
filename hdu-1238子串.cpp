#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
void copy(char* sub, char* s, int i, int j) {
	int count = 0;
	for (; i <= j; i++)
		sub[count++] = s[i];
	sub[count] = '\0';
}
void reverse_str(char* resub, char* sub) {
	int len = strlen(sub);
	for (int i = len - 1; i >= 0; i--)
		resub[len - i - 1] = sub[i];
	resub[len] = '\0';
}
int main()
{
	char s[110][110], sub[110], resub[110];
	int t, n, i, j, k, res;
	cin >> t;
	while (t--) {
		cin >> n;
		memset(s, 0, sizeof(s));
		memset(sub, 0, sizeof(sub));
		memset(resub, 0, sizeof(resub));
		for (i = 0; i < n; i++)
			cin >> s[i];
		for (i = 0; i < n; i++) {
			k = i;
			for (j = i + 1; j < n; j++) {
				if (strlen(s[j]) < strlen(s[k])) {
					k = j;
				}
			}
			if (k != i) {
				swap(s[i], s[k]);
			}
		}
		res = 0;
		for (i = 0; i < strlen(s[0]); i++) {
			for (j = i; j < strlen(s[0]); j++) {
				copy(sub, s[0], i, j);
				reverse_str(resub, sub);
				for (k = 1; k < n; k++) {
					if (!strstr(s[k], sub) && !strstr(s[k], resub))		//strstr函数用于判断字符串sub是否是字符串s[k]的子串
						break;											//如果是，则该函数返回sub在s[k]中首次出现的地址；否则，返回NULL
				}
				if (k == n && strlen(sub) > res) res = strlen(sub);
			}
		}
		cout << res << endl;
	}
	return 0;
}