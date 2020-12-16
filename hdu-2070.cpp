#include<iostream>
int main()
{
	long long f[51] = { 0,1,1,2 };
	int n;
	for (int i = 4; i <= 50; i++)
		f[i] = f[i - 1] + f[i - 2];
	while (std::cin >> n && n != -1)
		std::cout << f[n] << std::endl;
	return 0;
}