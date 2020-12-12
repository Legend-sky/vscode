/*
 * @Autor: Whx
 * @Date: 2020-11-02 17:13:17
 * @LastEditTime: 2020-11-25 20:43:07
 */
// #include <bits/stdc++.h>
// #define ll long long

// using namespace std;

// int main()
// {
//     // double x[10];
//     // x[1] = -1.2;
//     // x[2] = -0.8;
//     // for (int i = 3; i <= 7; i++)
//     // {
//     //     double a = 12 * pow(x[i - 2], 3) - 12 * pow(x[i - 2], 2) - 24 * x[i - 2];
//     //     double b = 12 * pow(x[i - 1], 3) - 12 * pow(x[i - 1], 2) - 24 * x[i - 1];
//     //     x[i] = x[i - 1] - 1.0 * (x[i - 1] - x[i - 2]) / (b - a) * b;
//     // }
//     // for (int i = 1; i <= 7; i++)
//     //     cout << x[i] << endl;
//     double x[10] = {0, -1.1, -0.991111, -0.983797};
//     double f[10];
//     for (int i = 1; i <= 3; i++)
//         f[i] = 3 * pow(x[i], 4) - 4 * pow(x[i], 3) - 12 * pow(x[i], 2);
//     double b1 = (x[2] * x[2] - x[3] * x[3]) * f[1];
//     double b2 = (x[3] * x[3] - x[1] * x[1]) * f[2];
//     double b3 = (x[1] * x[1] - x[2] * x[2]) * f[3];
//     double c1 = (x[2] - x[3]) * f[1];
//     double c2 = (x[3] - x[1]) * f[2];
//     double c3 = (x[1] - x[2]) * f[3];
//     x[4] = 0.5 * (b1 + b2 + b3) / (c1 + c2 + c3);
//     cout << "x4 = " << x[4] << endl;
//     f[4] = 3 * pow(x[4], 4) - 4 * pow(x[4], 3) - 12 * pow(x[4], 2);
//     for (int i = 1; i <= 4; i++)
//         cout << "f[" << i << "] = " << f[i] << endl;
//     return 0;
// }

// int main()
// {
//     double D = 0;
//     double a[10] = {0.2, 0.8};
//     for (int i = 0; i < 2; i++)
//     {
//         D += a[i] * log(a[i]) / log(2);
//     }
//     cout << -D << endl;
//     cout << double(0.97 - 1.0 / 3 * 0.72 - 0.4 * 0.918);
//     return 0;
// }
// int main()
// {
//     cout << typeid(bool).name() << endl;
//     cout << typeid(float).name() << endl;
//     cout << typeid(double).name() << endl;
//     return 0;
// }inc
#include <stdio.h>
int narcissistic(int number);
void PrintN(int m, int n);

int main()
{
    int n, m;
    scanf("%d %d", &m, &n);
    if (narcissistic(m))
        printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if (narcissistic(n))
        printf("%d is a narcissistic number\n", n);
    return 0;
}
int narcissistic(int number)
{
    int sum = 0, tmp = number;
    while (tmp > 0)
    {
        int a = tmp % 10;
        sum += a * a * a;
        tmp /= 10;
    }
    if (sum == number)
        return 1;
    else
        return 0;
}
void PrintN(int m, int n)
{
    for (int i = m + 1; i <= n - 1; i++)
    {
        if (narcissistic(i))
            printf("%d\n", i);
    }
}