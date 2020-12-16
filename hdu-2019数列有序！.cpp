#include<iostream>
using namespace std;
int main(){
	int i,n,m,a[101],k,f;
	while(cin >> n >> m && (n != 0 || m != 0)){
		k = -1;
		f = n;
		for(i = 0; i < n; i++)
			cin >> a[i];
		for(i = 0; i < n; i++){
			if(a[i] > m){
				k = i;
				break;
			}
		}
		if(k == -1){
			a[n] = m;
		}
		else{
			while(f != k){
				a[f] = a[f-1];
				f--;
			}
			a[k] = m;
		}
		for(i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << a[n] << endl;
	}
} 
