#include<iostream>
using namespace std;
int sum;
void dfs(int m){		//Ҳ�����õ���,����m�ķ�ʽ=����m-1�ķ�ʽ���ϵ���m-2�ķ�ʽ
	int i;
	if(m == 0) return;
	if(m == 1){
		sum++;
		return;
	}
	for(i = 1; i <= 2; i++){
		dfs(m-i);
	}
	return;
}
int main(){
	int n,m;
	cin >> n;
	while(n--){
		sum = 0;
		cin >> m;
		dfs(m);
		cout << sum << endl;
	}
	return 0;
}
