/*
 * @Autor: Whx
 * @Date: 2020-10-25 10:13:26
 * @LastEditTime: 2020-10-25 13:46:15
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>

using namespace std;

struct Status
{
	int n;
	char start, mid, end;
	Status(int n, char A, char B, char C) : n(n), start(A), mid(B), end(C) {}
};

void solve(int n, char A, char B, char C)
{
	stack<Status> mys;
	mys.push(Status(n, A, B, C));
	while (!mys.empty())
	{
		Status ns = mys.top();
		mys.pop();
		if (ns.n == 1)
		{
			printf("%c -> %c\n", ns.start, ns.end);
		}
		else
		{
			mys.push(Status(ns.n - 1, ns.mid, ns.start, ns.end));
			mys.push(Status(1, ns.start, ns.mid, ns.end));
			mys.push(Status(ns.n - 1, ns.start, ns.end, ns.mid));
		}
	}
}
int main()
{
	int n;
	cin >> n;
	solve(n, 'a', 'b', 'c');
	return 0;
}
