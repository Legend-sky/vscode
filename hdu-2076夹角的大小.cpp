#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int h, m, s, t;
	double x, y, a;		//x��ʾʱ����12��ļнǣ�y��ʾ������60�ļнǣ�a��ʾʱ��ͷ���ļн�
	cin >> t;
	while (t--)
	{
		cin >> h >> m >> s;
		if (h >= 12) h -= 12;
		x = (h + (m + s / 60.0) / 60.0) * 30.0;
		y = (m + s / 60.0) * 6.0;
		a = abs(x - y);
		a > 180 ? a = 360 - a : a = a;
		cout << (int)a << endl;
	}
	return 0;
}