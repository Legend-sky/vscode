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
			dfs(step+1);		//��һ��ִ�е������֮��ļ��ζ��Ῠ�����ֱ��step�������һ����һ���һ�������֮����forѭ������ÿ�ֿ����� 
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
