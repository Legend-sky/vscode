#include<iostream>
using namespace std;
int main()
{
    int m, k, day;
    while (cin >> m >> k)
    {
        if (m == 0 && k == 0) break;
        day = 0;
        while (m)
        {
            day++;
            m--;
            if (day % k == 0) m++;
        }
        cout << day << endl;
    }
    return 0;
}