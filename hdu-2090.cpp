#include<cstdio>
#include<cstring>
#include<algorithm>
int main()
{
	char c[50];
	double a, b, res = 0;
	while (scanf("%s%lf%lf", c, &a, &b) != EOF)
	{
		res += a * b;
	}
	printf("%.1lf\n", res);
	return 0;
}