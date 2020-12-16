#include<iostream>
using namespace std;
int main(){
	int b[10] = {100,50,10,5,2,1};
	int sum,i,j,n,a[100];
	while(cin >> n && n != 0){
		sum = 0;
		for(i = 0; i < n; i++)
			cin >> a[i];
		for(i = 0; i < n; i++){
			j = 0;
			while(a[i] > 0){
				if(a[i] - b[j] >= 0){
					sum++;
					a[i] = a[i] - b[j];
					if(a[i] < b[j] && a[i] - b[j] != 0) j++;
				}
				else j++;
			}
		}
		cout << sum <<endl;
	}
} 
