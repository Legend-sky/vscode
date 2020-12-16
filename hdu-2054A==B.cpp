#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int qutou(string& a)
{
	while ((a[0] <= '0' || a[0] > '9') && a[1] != '.')
		a.erase(0, 1);
	return 1;
}
int quwei(string& a)
{
	int len = a.length();
	bool f = false;
	for (int i = 0; i < len; ++i)
	{
		if (a[i] == '.')
		{
			f = true;
			break;
		}
	}
	if (f)
	{
		while (a[a.length() - 1] == '0')
			a.erase(a.length() - 1, 1);
		if (a[a.length() - 1] == '.')
			a.erase(a.length() - 1, 1);
	}
	return 1;
}
bool fuhao(string& a)
{
	if (a[0] == '-') return false;
	else return true;
}
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		if (a.length() == 2 && b.length() == 2 && a[0] == '+' && b[0] == '-' && a[1] == '0' && b[1] == '0') {
			cout << "YES" << endl;
			continue;
		}
		if (fuhao(a) != fuhao(b)) {
			cout << "NO" << endl;
			continue;
		}
		qutou(a); qutou(b);
		quwei(a); quwei(b);
		if (a == b) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}