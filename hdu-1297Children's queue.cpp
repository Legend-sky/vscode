#include<iostream>
#include<cstring>
using namespace std;
int f[1005][1005];
void c(){
	memset(f,0,sizeof(f));
	f[0][0] = 1;
	f[1][0] = 1;
	f[2][0] = 2;
	f[3][0] = 4;
	f[4][0] = 7;
	int i,j,t;
	for(i = 5; i < 1005; i++){
		for(j = 0; j < 1005; j++){
			f[i][j] = f[i-1][j] + f[i-2][j] + f[i-4][j];
		}
		for(j = 0; j < 1005; j++){
			if(f[i][j] > 9){
				t = f[i][j] / 10;
				f[i][j] = f[i][j]%10;
				f[i][j+1] += t;
			}
		}
	}
}
int main(){
	int n,i;
	c();
	while(cin >> n){
		i = 1004;
		while(f[n][i] == 0){
			i--;
		}
		for(; i >= 0; i--)
			cout << f[n][i];
		cout << endl;
	}
}
