/*1.��p����������a ^ p �� a(mod p)
2.����ax + by = z�н�(x, y)�ĳ�Ҫ������gcd(a, b) | z

��1�ã�x ^ 13 �� x(mod 13), 5 * x ^ 13 �� 5x(mod 65).ͬ��13 * x ^ 5 �� 13x(mod 65)
������ʽ ��(18 + ka) * x(mod 65), ����Ѱ������(18 + ka) | 65����Сa

����ȷʵ����������a, ��ô18 = 65b - ka(b������), ��2��gcd(65, k) | 18, 
����65������5��13����������18, ֻ��1������18, ��gcd(65, k)��Ϊ1���޽�.
����ó�(18 + ka) | 65����*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int k, i;
	while (cin >> k) {
		for (i = 1; i <= 65; i++) {
			if ((18 + k * i) % 65 == 0) break;
		}
		if (i <= 65) cout << i << endl;
		else cout << "no" << endl;
	}
	return 0;
}