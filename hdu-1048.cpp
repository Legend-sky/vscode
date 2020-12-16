#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char sen[200];
	char start[12];
	int i,len;
	
	while(cin.getline(start,12,'\n')){
		if(strcmp(start,"START") == 0){
			cin.getline(sen,200,'\n');
			len = strlen(sen);
			for(i = 0; i < len; i++){
				if(sen[i] >= 'A' && sen[i] <= 'Z')
					sen[i] = (sen[i] - 44) % 26 + 65;
			}
			cout << sen << endl;
		}
		else if(strcmp(start,"ENDOFINPUT") == 0)
			break;
	}
}
