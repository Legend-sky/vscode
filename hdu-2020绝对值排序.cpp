#include<iostream>
using namespace std;
int abs(int x){
	x > 0 ? x=x : x=-x;
	return x;
}
int main(){
	int a[101],n,m,i,j,k,temp;
	while(cin >> n && n != 0){
		for(i = 0; i < n; i++)
			cin >> a[i];
		for(i = 0; i < n-1; i++){
			k = i;
			for(j = i+1; j < n; j++){
				if(abs(a[j]) > abs(a[k])) k = j;
			}
			if(k != i){
				temp = a[k];
				a[k] = a[i];
				a[i] = temp;
			}
		}
		for(i = 0; i < n-1; i++)
			cout << a[i] << ' ';
		cout << a[n-1] << endl;
	}
}
