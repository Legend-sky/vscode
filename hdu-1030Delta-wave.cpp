#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m) {
		int nfloor, mfloor, nleft, mleft, nright, mright;
		nfloor = sqrt(n - 1) + 1;		//�Ѿ���int�ͣ����Լ�ȡ��
		mfloor = sqrt(m - 1) + 1;
		nleft = (n - (nfloor - 1) * (nfloor - 1) - 1 + 2) / 2;	//��n�ڵڼ����У�ÿ�е�һ��Ԫ��ֵΪ(nfloor-1)^2+1
		mleft = (m - (mfloor - 1) * (mfloor - 1) - 1 + 2) / 2;	//��n��ȥÿ�е�һ������Ȼ���2���Զ�����
		nright = (nfloor * nfloor - n + 2) / 2;		//ͬ��ÿ�����һ��Ԫ����nfloor*nfloor,��ȥn�ټ�2����
		mright = (mfloor * mfloor - m + 2) / 2;
		cout << abs(nfloor - mfloor) + abs(nleft - mleft) + abs(nright - mright) << endl;
	}
}