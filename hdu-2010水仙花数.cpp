#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int m,n,i,f;
	while(cin >> m >> n){
		f = 0;
		for(i = m; i <= n; i++){
			if(pow(i/100,3) + pow(i/10%10,3) + pow(i%10,3) == i){
				f++;
				if(f > 1)
					cout << ' ' << i;
				else 
					cout << i;
			}
		}
		if(f >= 1)
			cout << endl;
		else
			cout << "no" << endl;			//两个字符以上要用两个引号！ 
	}
}
