/*
 * @Author: Whx
 * @Date: 2020-12-31 21:44:59
 * @LastEditTime: 2021-01-01 20:08:56
 */
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    int t;
    char s[100];
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        gets(s);
        bool f = 0;
        int i;
        for (i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == 'P' && s[i + 1] == 'T' && s[i + 2] == 'A')
            {
                f = 1;
            }
        }
        if (s[i - 1] != '?')
            printf("enen\n");
        else
        {
            if (f)
                printf("Yes!\n");
            else
                printf("No.\n");
        }
    }
    return 0;
}