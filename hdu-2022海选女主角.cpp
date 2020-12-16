#include<iostream>
using namespace std;
int abs(int x){
	x > 0 ? x = x : x = -x;
	return x;
}
int main(){
	int a[100][100];
	int n,m,i,j,m1,n1,max;
	while(cin >> m >> n && n != 0 && m != 0){
		max = -1;
		for(i = 1; i <= m; i++){
			for(j = 1; j <= n; j++){
				cin >> a[i][j];
				if(abs(a[i][j]) > max){
					max = abs(a[i][j]);
					m1 = i;
					n1 = j;
				}
			}
		}
		cout << m1 << ' ' << n1 << ' ' << a[m1][n1] << endl;
	}
} 
