#include<iostream>
int a[100],book[100],n;
using namespace std;
void dfs(int step){
	int i;
	if(step == n+1){
		for(i = 1; i <= n; i++)
			cout << a[i];
		cout << endl;
		return;
	}
	for(i = 1; i <= n; i++){
		if(book[i] == 0){
			a[step] = i;
			book[i] = 1;
			dfs(step+1);		//第一次执行到这里后之后的几次都会卡在这里，直到step到了最后一个加一输出一种情况，之后由for循环遍历每种可能性 
			book[i] = 0;
		}
	}
	return;
}
int main(){
	while(cin >> n)
		dfs(1);
	
	return 0;
}
