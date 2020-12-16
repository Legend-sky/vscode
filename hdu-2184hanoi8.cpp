/*
定义数组a，其中a[i]表示完成一次i层汉诺塔移动的次数。
指针o,p,q分别表示三个位置。
起始状态为n层都在o上，要往q方向移动。
然后分成两种情况：
1、
m<=a[n-1];
此时，第n层没机会移动，那么就相当于o上的n-1层往p上移动。
使其状态和起始状态一致，我们要交换p和q。
2、
m>a[n-1];
此时，先进行到下面状态，上面n-1层移动到p位置，第n层移动到q位置，消耗了a[n-1]+1次移动。
接下来就变成p上的n-1层往q上移动，只要交换o,p，令m=m-a[n-1]-1即可。
通过上述操作，都可以得到第n层的位置，并且问题变成n-1层都在o上，要往q方向移动。
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	unsigned long long m, a[65];
	int row[3][65];
	a[0] = 0;
	a[1] = 1;
	for (int i = 2; i <= 63; i++)
		a[i] = a[i - 1] * 2 + 1;
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n >> m;
		int* start, * mid, * end;
		start = row[0];
		mid = row[1];
		end = row[2];
		*start = *mid = *end = 1;
		while (n)							//递归真伟大...
		{
			n--;
			if (m <= a[n])
			{
				*(start + *start) = n + 1;	//把开始位置的最后一位固定
				(*start)++;					//开始位置多一个盘子
				swap(end, mid);				//交换后两个,下次递归就会把盘子换到中间
			}
			else
			{
				*(end + *end) = n + 1;		//把end位置最后一个加个盘子
				(*end)++;					//end位置的盘子数加一
				swap(start, mid);			//交换前两个,相当于把n-1个盘子从start->mid,这里消耗了a[n-1]步
				m = m - a[n] - 1;			//此过程一共消耗a[n-1]+1步,由于前面n--了,所以这里减去a[n]
			}
		}
		for (int i = 0; i < 3; i++)
		{
			cout << row[i][0] - 1;
			for (int j = 1; j < row[i][0]; j++)
				cout << ' ' << row[i][j];
			cout << endl;
		}
	}
	return 0;
}