/*1.若p是质数，则a ^ p ≡ a(mod p)
2.方程ax + by = z有解(x, y)的充要条件是gcd(a, b) | z

由1得：x ^ 13 ≡ x(mod 13), 5 * x ^ 13 ≡ 5x(mod 65).同理13 * x ^ 5 ≡ 13x(mod 65)
整个算式 ≡(18 + ka) * x(mod 65), 于是寻找满足(18 + ka) | 65的最小a

假设确实存在这样的a, 那么18 = 65b - ka(b是整数), 由2得gcd(65, k) | 18, 
由于65的因子5和13均不能整除18, 只有1能整除18, 故gcd(65, k)不为1将无解.
计算得出(18 + ka) | 65即可*/
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