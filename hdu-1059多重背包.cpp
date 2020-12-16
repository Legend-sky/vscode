#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[120000];
int v;
void ZeroOnePack(int cost, int weight) {		//01����
	int i;
	for (i = v; i >= cost; i--)
		dp[i] = max(dp[i], dp[i - cost] + weight);
}
void CompletePack(int cost, int weight) {		//��ȫ����
	int i;
	for (i = cost; i <= v; i++)
		dp[i] = max(dp[i], dp[i - cost] + weight);
}
void MultiplePack(int cost, int weight, int num) {		//���ر���
	if (cost * num > v) {
		CompletePack(cost, weight);
		return;
	}
	int k = 1;
	while (k < num) {	//�������Ż������1��2��4��...
		ZeroOnePack(k * cost, k * weight);
		num -= k;
		k *= 2;
	}
	ZeroOnePack(num * cost, num * weight);	//������²���2���ݴε���
}
int main()
{
	int num = 0, i, j, sum, a[120000];
	while (1) {
		sum = 0;
		for (i = 1; i <= 6; i++) {
			cin >> a[i];
			sum += i * a[i];
		}
		if (!sum) break;
		cout << "Collection #" << ++num << ':' << endl;
		if (sum % 2 == 1) {
			cout << "Can't be divided." << endl;
		}
		else {
			v = sum / 2;
			memset(dp, 0, sizeof(dp));
			for (i = 1; i <= 6; i++)
				MultiplePack(i, i, a[i]);
			if (dp[v] == v) {
				cout << "Can be divided." << endl;
			}
			else {
				cout << "Can't be divided." << endl;
			}
		}
		cout << endl;
	}
	return 0;
}