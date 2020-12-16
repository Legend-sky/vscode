#include<iostream>
using namespace std;
int main(){
	int a[31][31];
	int i,j,n;
	for(i = 1; i <= 30; i++)
		a[i][1] = a[i][i] = 1;
	for(i = 3; i <= 30; i++){
		for(j = 2; j <= i-1; j++){
			a[i][j] = a[i-1][j] + a[i-1][j-1];
		}
	}
	while(cin >> n){
		for(i = 1; i <= n; i++){
			for(j = 1; j <i; j++){
				cout << a[i][j] << ' ';
			}
			cout << a[i][i] << endl;
		}
		cout << endl;
	}
} 
