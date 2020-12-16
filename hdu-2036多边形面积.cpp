#include<iostream>
#include<iomanip>
using namespace std;
struct hdu{
	int x;
	int y;
}s[100];
int main(){
	cout << fixed << setprecision(1);
	int n,i;
	double res = 0;
	while(cin >> n && n != 0){
		res = 0;
		for(i = 0; i < n; i++)
			cin >> s[i].x >> s[i].y;
		for(i = 0; i < n-1; i++)
			res += (s[i].x*s[i+1].y - s[i+1].x*s[i].y);		//鞋带公式,求多边形面积
		res += (s[n-1].x*s[0].y - s[0].x*s[n-1].y);
		if(res < 0) res = -res;
		res = res/2;
		cout << res << endl;
	}
}
