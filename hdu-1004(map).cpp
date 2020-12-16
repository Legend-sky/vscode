#include<iostream>
#include<map>
using namespace std;
int main(){
	int n,i,max,k;
	char c[1005][16];
	map<string, int>a;
	while(cin >> n && n != 0){
		max = 0;
		k = 0;
		a.clear();
		for(i = 0; i < n; i++){
			cin >> c[i];
			a[c[i]]++;
		}
		for(i = 0; i < n; i++){
			if(max < a[c[i]]){
				max = a[c[i]];
				k = i;
			}
		}
		cout << c[k] << endl;
	}
	return 0;
}
