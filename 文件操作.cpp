/*
 * @Autor: Whx
 * @Date: 2020-11-07 21:02:39
 * @LastEditTime: 2020-11-07 22:01:56
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void test()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);
    char c;
    while ((c = ifs.get()) != EOF)
    {
        cout << c;
    }
    ifs.close();
}
int main()
{
    test();
    return 0;
}