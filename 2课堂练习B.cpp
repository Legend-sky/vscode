/*
 * @Author: Whx
 * @Date: 2021-01-06 18:38:34
 * @LastEditTime: 2021-01-06 19:28:01
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define ll long long

using namespace std;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

struct Node
{
    char name[12];
    int age;
    double score;
} m[105];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s%d%lf", &m[i].name, &m[i].age, &m[i].score);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (m[j].score < m[j + 1].score)
                {
                    swap(m[j], m[j + 1]);
                }
                if (m[j].score == m[j + 1].score && m[j].age > m[j + 1].age)
                {
                    swap(m[j], m[j + 1]);
                }
                if (m[j].score == m[j + 1].score && m[j].age == m[j + 1].age && strcmp(m[j].name, m[j + 1].name) > 0)
                {
                    swap(m[j], m[j + 1]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%s %d %.2lf\n", m[i].name, m[i].age, m[i].score);
        }
    }
    return 0;
}
