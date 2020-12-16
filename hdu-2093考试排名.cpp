#include<cstdio>
#include<set>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	set<string> a, b;
	char s1[50], s2[50];
	int n;
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%s %s", s1, s2);
			a.insert(s1);
			a.insert(s2);
			b.insert(s2);
		}
		if (a.size() - b.size() == 1) printf("Yes\n");
		else printf("No\n");
		a.clear();
		b.clear();
	}
	return 0;
}