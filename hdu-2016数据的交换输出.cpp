#include<iostream>
using namespace std;
int main(){
	int i,j,n,a[100],min,temp;
	while(cin >> n && n != 0){
		min = 99999999;
		for(i = 0; i < n; i++)
			cin >> a[i];
		for(i = 0; i < n; i++){
			if(a[i] < min){
				min = a[i];
				j = i;
			}
		}
		if(a[0] == min){
			for(i = 0; i < n - 1; i++)
				cout << a[i] << ' ';
			cout << a[n-1] << endl;
		}
		else{
			temp = a[j];
			a[j] = a[0];
			a[0] = temp;
			for(i = 0; i < n - 1; i++)
				cout << a[i] << ' ';
			cout << a[n-1] << endl;
		}
	} 
}
