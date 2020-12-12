/*
 * @Author: Whx
 * @Date: 2020-11-25 14:57:37
 * @LastEditTime: 2020-11-25 15:16:20
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int n, p, h[1500], num;
    memset(h, -1, sizeof(h));
    cin >> n >> p;
    cin >> num;
    h[num % p] = num;
    cout << num % p;
    for (int i = 1; i < n; i++)
    {
        cin >> num;
        int t = num % p;
        while (h[t] != -1)
        {
            if (h[t] == num)
                break;
            t++;
            if (t == p)
                t = 0;
        }
        h[t] = num;
        cout << " " << t;
    }
    return 0;
}
