#include<iostream>
using namespace std;
int main(){
	int n,a,b,i,sum1,sum2;
	cin >> n;
	while(n--){
		cin >> a >> b;
		sum1 = 0;
		sum2 = 0; 
		for(i = 1; i <= a/2+1; i++){
			if(a%i == 0) sum1 += i;
		}
		for(i = 1; i <= b/2+1; i++){
			if(b%i == 0) sum2 += i;
		}
		if(sum1 == b && sum2 == a) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
} 
