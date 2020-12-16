#include<iostream>
#include<map>
#include<cstring>
using namespace std;
int main(){
	int n,i,j,k,a[1000],max;			//刚开始数组开100,死活过不去,以为不会这么大,还是太年轻
	char c[1000][16];
	while(cin >> n && n != 0){
		for(i = 0; i < n; i++){
			cin >> c[i];
		}
		for(i = 0; i < n; i++){
			a[i] = 0;
			for(j = 0; j < n; j++){
				if(strcmp(c[i],c[j]) == 0) a[i]++;
			}
		}
		max = a[0];
		k = 0;
		for(i = 1; i < n; i++){
			if(a[i] > max){
				max = a[i];
				k = i;
			}
		}
		cout << c[k] << endl;
	}
	return 0;
} 
