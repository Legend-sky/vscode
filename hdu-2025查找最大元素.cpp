#include<iostream>
#include<cstring>
using namespace std;
void insert(char s1[], char s2[], int n){
	int i,n1,n2;
	n1=strlen(s1);
	n2=strlen(s2);
	for(i = n1; i > n; i--){
		s1[i+n2] = s1[i];
	}
	for(i = 0; i < n2; i++){
		s1[n+i+1] = s2[i];
	}
}
int main(){
	int i,n;
	char max;
	char ch[601];
	while(gets(ch)){
		max = -1;
		n = 0;
		for(i = 0; ch[i] != '\0'; i++){
			if(ch[i] > max) max = ch[i];
			n++;
		}
		for(i = n-1; i >= 0; i--){
			if(ch[i] == max){
				insert(ch,"(max)",i);
			}			
		}
		cout << ch << endl;
	}
} 
