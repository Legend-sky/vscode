/*
 * @Author: Whx
 * @Date: 2020-11-06 21:32:56
 * @LastEditTime: 2020-12-04 23:43:25
 */
#include <iostream>
using namespace std;
void preorder(int *post, int *in, int n1)
{
    if (n1 > 0)
    {
        cout << " " << post[n1 - 1];
        int tmp = post[n1 - 1];
        int num = 0;
        for (int i = 0; i < n1; i++)
        {
            if (in[i] == tmp)
            {
                num = i;
                break;
            }
        }
        preorder(post, in, num);
        preorder(post + num, in + num + 1, n1 - num - 1);
    }
}
int main()
{
    int post[40], in[40];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> post[i];
    for (int i = 0; i < n; i++)
        cin >> in[i];
    cout << "Preorder:";
    preorder(post, in, n);
}