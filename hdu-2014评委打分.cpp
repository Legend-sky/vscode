#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	cout << fixed << setprecision(2);
	int n,m;
	double score,sum,max,min;
	while(cin >> n){
		max = -1,min = 101;
		m = n;
		sum = 0;
		while(n--){
			cin >> score;
			if(score > max) max = score;
			else if(score < min) min = score;
			sum += score;
		}
		sum = sum - min - max;
		sum = sum / (1.0*(m - 2));
		cout << sum << endl;
	}
}

