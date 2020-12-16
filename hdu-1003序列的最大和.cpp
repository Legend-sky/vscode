//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int a[100010];
//int main()
//{
//	int i, j, n, m, start, end, sum, maxn, position, num = 1;
//	cin >> n;
//	while (n--) {
//		cin >> m;
//		for (i = 1; i <= m; i++)
//			cin >> a[i];
//		start = end = position = 1;
//		maxn = sum = a[1];
//		for (i = 2; i <= m; i++) {
//			if (sum + a[i] < a[i]) {
//				sum = a[i];
//				position = i;
//			}
//			else {
//				sum += a[i];
//			}
//			if (sum > maxn) {
//				maxn = sum;
//				start = position;
//				end = i;
//			}
//		}
//		cout << "Case " << num++ << ":" << endl;
//		cout << maxn << ' ' << start << ' ' << end << endl;
//		if (n) cout << endl;
//	}
//	return 0;
//}
/*
 * @Autor: Whx
 * @Date: 2020-10-28 16:59:04
 * @LastEditTime: 2020-10-28 17:22:34
 */
#include <bits/stdc++.h>

using namespace std;

int n, k = 1;
int a[100005];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int st = 1, en;
        int ans_st, ans_en;
        int res, tmp;
        res = -9999999;
        tmp = a[1];
        ans_st = ans_en = 1;
        for (int i = 2; i <= n; i++)
        {
            tmp += a[i];
            if (tmp >= res)
            {
                res = tmp;
                en = i;
                ans_st = st;
                ans_en = en;
            }
            else if (tmp < 0)
            {
                st = i + 1;
                tmp = 0;
            }
        }
        cout << "Case " << k++ << ":" << endl;
        cout << res << " " << ans_st << " " << ans_en << endl;
        cout << endl;
    }
    return 0;
}
