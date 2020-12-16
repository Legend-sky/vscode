#include<iostream>
using namespace std;
int main()
{
	int n,k,t,q;
	while(cin >> n && n != 0)
	{
		k = n/1000 + n/100%10 + n/10%10 + n%10;
		t = n/4096 + n/256%16 + n/16%16 + n%16;
		q = n/1728 + n/144%12 + n/12%12 + n%12;
		if(k == t && t == q)
			cout << n << " is a Sky Number." << endl;
		else
			cout << n << " is not a Sky Number." << endl;
	}
}
