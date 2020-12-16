//                            _ooOoo_    
//                           o8888888o    
//                           88" . "88    
//                           (| -_- |)    
//                            O\ = /O    
//                        ____/`---'\____    
//                      .   ' \\| |// `.    
//                       / \\||| : |||// \    
//                     / _||||| -:- |||||- \    
//                       | | \\\ - /// | |    
//                     | \_| ''\---/'' | |    
//                      \ .-\__ `-` ___/-. /    
//                   ___`. .' /--.--\ `. . __    
//                ."" '< `.___\_<|>_/___.' >'"".    
//               | | : `- \`.;`\ _ /`;.`/ - ` : | |    
//                 \ \ `-. \_ __\ /__ _/ .-` / /    
//         ======`-.____`-.___\_____/___.-`____.-'======    
//                            `=---='    
//    
//         .............................................    
//                  佛祖保佑             永无BUG
//#include<iostream>
//#include<cstdio>
//#include<iomanip>
//using namespace std;
//int i, k, m, n;
//double j[1005], f[1005], h[1005], res, temp;
//void quicksort_three(double a[], double m[], double n[], int b, int c) {
//	if (b >= c) return;
//	int i = b;
//	int j = c;
//	double k = a[b];
//	double m1 = m[b];
//	double n1 = n[b];
//	while (i < j) {
//		while (i < j) {
//			if (k <= a[j]) {
//				j--;
//			}
//			else {
//				a[i] = a[j];
//				m[i] = m[j];
//				n[i] = n[j];
//				i++;
//				break;
//			}
//		}
//		while (i < j) {
//			if (k > a[i]) {
//				i++;
//			}
//			else {
//				a[j] = a[i];
//				m[j] = m[i];
//				n[j] = n[i];
//				j--;
//				break;
//			}
//		}
//	}
//	a[i] = k;
//	m[i] = m1;
//	n[i] = n1;
//	quicksort_three(a, m, n, b, i - 1);
//	quicksort_three(a, m, n, j + 1, c);
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	//cout << fixed << setprecision(3);
//	while (cin >> m >> n && m != -1 && n != -1) {
//		res = 0;
//		for (i = 1; i <= n; i++) {
//			cin >> j[i] >> f[i];
//			h[i] = 1.0 * j[i] / f[i];
//		}
//		quicksort_three(h, j, f, 1, n);
//		/*for (i = 1; i < n; i++) {
//			for (k = 1; k <= n - i; k++) {
//				if (h[k] > h[k + 1]) {
//					temp = h[k];
//					h[k] = h[k + 1];
//					h[k + 1] = temp;
//					temp = j[k];
//					j[k] = j[k + 1];
//					j[k + 1] = temp;
//					temp = f[k];
//					f[k] = f[k + 1];
//					f[k + 1] = temp;
//				}
//			}
//		}*/
//		for (i = n; i > 0; i--) {
//			if (m - f[i] >= 0) {
//				res += j[i];
//				m -= f[i];
//			}
//			else {
//				res += 1.0 * m * h[i];
//				break;
//			}
//		}
//		//cout << res << endl;
//		printf("%.3lf\n", res);
//	}
//	return 0;
//}

//结构体的排序
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

struct Room {
	int j, f;
	double rate;
}r[1000];

int cmp(Room a, Room b) {
	return a.rate > b.rate;
}

int m, n;

int main() {
	int i;
	double sum;
	while (scanf("%d%d", &m, &n)) {
		sum = 0;
		if (m == -1 && n == -1) break;
		for (i = 0; i < n; i++) {
			scanf("%d%d", &r[i].j, &r[i].f);
			r[i].rate = 1.0 * r[i].j / r[i].f;
		}
		sort(r, r + n, cmp);
		for (i = 0; i < n; i++) {
			if (m > r[i].f) {
				sum += r[i].j;
				m -= r[i].f;
			}
			else {
				sum += 1.0 * r[i].j * m / r[i].f;
				break;
			}
		}
		printf("%.3lf\n", sum);
	}
}
