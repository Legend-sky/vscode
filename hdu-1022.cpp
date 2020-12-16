#include<iostream>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;
int main()
{
	string a, b;
	int n, i, j;
	while (cin >> n >> a >> b)
	{
		stack<int> s;
		vector<string> res;
		j = 0;
		for (i = 0; i < a.size(); i++)
		{
			res.push_back("in");
			s.push(a[i]);
			while (!s.empty() && s.top() == b[j])
			{
				res.push_back("out");
				s.pop();
				j++;
			}
		}
		if (j == n)
		{
			cout << "Yes." << endl;
			for (i = 0; i < res.size(); i++)
				cout << res[i] << endl;
		}
		else
			cout << "No." << endl;
		cout << "FINISH" << endl;
	}
	return 0;
}