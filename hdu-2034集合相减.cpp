#include<iostream>
using namespace std;
int a[101],b[101];
void quicksort(int a[],int low,int high){
	if(high <= low) return;
	int i = low;
	int j = high+1;
	int k = a[low];
	int temp;
	while(1){
		while(a[++i] < k){
			if(i == high) break;
		}
		while(a[--j] > k){
			if(j == low) break;
		}
		if(i >= j) break;
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	a[low] = a[j];
	a[j] = k;
	quicksort(a,low,j-1);
	quicksort(a,j+1,high);
}
int main(){
	int n,m,i,j,k;
	while(cin >> n >> m && (n != 0 || m != 0)){
		for(i = 1; i <= n; i++)
			cin >> a[i];
		for(j = 1; j <= m; j++)
			cin >> b[j];
		quicksort(a,1,n);
		quicksort(b,1,m);
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++){
				if(a[i] == b[j]){
					for(k = i; k < n; k++){
						a[k] = a[k+1];
					}
					n--;
					i--;
				}
			}
		}
		if(n == 0) cout << "NULL" << endl;
		else{
			for(i = 1; i <=n; i++)
				cout << a[i] << ' ';
			cout << endl;
		}
	}
	return 0;
} 
