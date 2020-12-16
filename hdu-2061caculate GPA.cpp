#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
	int n, k;
	double c[100], s[100], c_sum, s_sum, gpa;
	char str[100];
	bool f;
	cin >> n;
	while (n--) {
		f = false;
		c_sum = 0;
		s_sum = 0;
		memset(c, 0, sizeof(c));
		memset(s, 0, sizeof(s));
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> str >> c[i] >> s[i];
			if (s[i] >= 0 && s[i] < 60) {
				f = true;
			}
		}
		if (f) cout << "Sorry!" << endl;
		else {
			for (int i = 0; i < k; i++) {
				c_sum += c[i];
				s_sum += c[i] * s[i];
			}
			gpa = s_sum / c_sum;
			cout << fixed << setprecision(2) << gpa << endl;
		}
		if (n) cout << endl;
	}
}