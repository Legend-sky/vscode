#include<iostream>
using namespace std;
int main()
{
	int n,m,res,i,cs,t,a,b;
	cin >> t;
	for(i = 0; i < t; i++)
	{
		cs = 0;
		while(cin >> n >> m && (n || m))
		{
			res = 0;
			cs++;
			for(a = 1; a <= n-2; a++)
				for(b = a+1; b <= n-1; b++)
						if((a*a + b*b + m)%(a*b) == 0) res++;
			cout << "Case " << cs << ": " << res << endl;
		}
		if(i < t-1) cout << endl;		//等于t-1就是最后一组,不用加换行
	}
}
