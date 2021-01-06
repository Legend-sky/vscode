/*
 * @Author: Whx
 * @Date: 2020-11-30 22:14:35
 * @LastEditTime: 2021-01-06 19:01:38
 */
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int f[20005], V, N, M; //V：总的费用 M：背包能承受的最大重量
int n[20005];          //储存每个物品的数量，无穷大则为INF
int c[20005];          //储存每个物品的费用
int w[20005];          //储存每个物品的价值
int m[20005];          //储存每个物品的重量
int f2[20005][20005];  //二维费用的背包
int groupN;            //分组背包的组数
int s[20005];          //每组背包的数量
void ZeroOnePack(int cost, int weight)
{
    for (int v = V; v >= cost; v--)
        f[v] = max(f[v], f[v - cost] + weight);
}
void CompletePack(int cost, int weight)
{
    for (int v = cost; v <= V; v++)
        f[v] = max(f[v], f[v - cost] + weight);
}
void MutiplePack(int cost, int weight, int count)
{
    if (cost * count >= V)
    {
        CompletePack(cost, weight);
        return;
    }
    int k = 1;
    while (k < count)
    {
        ZeroOnePack(k * cost, k * weight);
        count -= k;
        k <<= 1;
    }
    ZeroOnePack(count * cost, count * weight);
}
void HybridPack()
{
    for (int i = 0; i < N; i++)
    {
        if (n[i] == 1)
            ZeroOnePack(c[i], w[i]);
        else if (n[i] == INF)
            CompletePack(c[i], w[i]);
        else if (n[i] > 1 && n[i] != INF)
            MutiplePack(c[i], w[i], n[i]);
    }
    cout << f[V] << endl;
}
void TwoDimensionalCostPack()
{
    memset(f2, 0, sizeof(f2));
    for (int i = 0; i < N; i++)
        for (int j = V; j >= c[i]; j--)
            for (int k = M; k >= m[i]; k--)
                f2[j][k] = max(f2[j][k], f2[j - c[i]][k - m[i]] + w[i]);
    cout << f2[V][M] << endl;
}
void GroupPack()
{
    for (int i = 0; i < groupN; i++)       //遍历每组
        for (int j = V; j >= 0; j--)       //背包容量从大到小
            for (int k = 0; k < s[i]; k++) //每组背包遍历
                if (j > c[k])
                    f[j] = max(f[j], f[j - c[k]] + w[i]);
    cout << f[V] << endl;
}