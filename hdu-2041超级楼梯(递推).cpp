#include<iostream>
using namespace std;
int main(){
	int n,m,i,a[41];		//��dfs��ʱ��,���ǵ��ƿ� 
	a[1] = 0;
	a[2] = 1;
	a[3] = 2;
	for(i = 4; i <= 40; i++)
		a[i] = a[i-1] + a[i-2];
	cin >> n;
	while(n--){
		cin >> m;
		cout << a[m] << endl;
	}
	return 0;
} 
