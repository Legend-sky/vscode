#include<iostream>
#include<cmath>
using namespace std;
int isprime(int m){
	int f = 1,i;
	for( i = 2; i < sqrt(m); i++){
		if(m % i == 0){
			f = 0;
			break;
		}
	}
	return f;
}
int main(){
	int x,y,n,i,f;
	while(cin >> x >> y && (x != 0 || y != 0)){
		f = 1;
		for(i = x; i <= y; i++){
			if(isprime(i*i + i + 41) == 0){
				f = 0;
				break;	
			}
		}
		if(f) cout << "OK" << endl;
		else cout << "Sorry" << endl;
	}
} 
