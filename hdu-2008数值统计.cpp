#include<iostream>
using namespace std;
int main(){
	double m;
	int n,a,b,c;
	while(cin >> n && n != 0){
		a = b = c = 0;
		while(n--){
			cin >> m;
			if(m < 0)
				a++;
			else if(m == 0)
				b++;
			else
				c++;
		}
		cout << a << ' ' << b << ' ' << c << endl; 
	}
} 
