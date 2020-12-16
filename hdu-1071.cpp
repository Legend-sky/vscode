#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	cout << fixed << setprecision(2);
	double x1,x2,x3,y1,y2,y3,s,s1,a,b,c;
	int n;
	cin >> n;
	while(n--){
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		cin >> x3 >> y3;
		if(y3 == y2) a = 0;
		a = 1.0 * (y2-y1) / (x1*x1 + x2*x2 - 2*x1*x2);
		b = -2*a*x1;
		c = a*x1*x1 + y1;
		s1 = 1.0/3*a*x3*x3*x3 + 1.0/2*b*x3*x3 + c*x3 - (1.0/3*a*x2*x2*x2 + 1.0/2*b*x2*x2 + c*x2);
		s = s1 - 1.0 * (y2 + y3) * (x3 - x2) / 2;
		if(s < 0) cout << -s << endl;
		else cout << s << endl;
	}
}
