#include<iostream>
using namespace std;
int main(){
	int n,ah,am,as,bh,bm,bs,ch,cm,cs;
	cin >> n;
	while(n--){
		ch = cm = cs = 0;
		cin >> ah >> am >> as >> bh >> bm >> bs;
		cs = as + bs;
		if(cs >= 60){
			cs -= 60;
			cm++;
		}
		cm += (am + bm);
		if(cm >= 60){
			cm -= 60; 
			ch++;
		}
		ch += (ah + bh);
		cout << ch << ' ' << cm << ' ' << cs << endl;
	}
} 
