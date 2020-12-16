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
		nfloor = sqrt(n - 1) + 1;		//已经是int型，会自己取整
		mfloor = sqrt(m - 1) + 1;
		nleft = (n - (nfloor - 1) * (nfloor - 1) - 1 + 2) / 2;	//求n在第几左行，每行第一个元素值为(nfloor-1)^2+1
		mleft = (m - (mfloor - 1) * (mfloor - 1) - 1 + 2) / 2;	//用n减去每行第一个数，然后加2除以二分组
		nright = (nfloor * nfloor - n + 2) / 2;		//同理，每行最后一个元素是nfloor*nfloor,减去n再加2分组
		mright = (mfloor * mfloor - m + 2) / 2;
		cout << abs(nfloor - mfloor) + abs(nleft - mleft) + abs(nright - mright) << endl;
	}
}