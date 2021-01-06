/*
 * @Author: Whx
 * @Date: 2021-01-01 18:58:02
 * @LastEditTime: 2021-01-05 22:09:26
 */
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define ll long long

using namespace std;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;

int n, a[N];
void Print(int a[])
{
    printf("%d", a[0]);
    for (int i = 1; i < n; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n");
}
void Bubble(int a[])
{
    for (int i = 0; i < n; i++)
    {
        bool f = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                f = 1;
            }
        }
        if (f == 0)
            break;
    }
}
void Insert(int a[])
{
    for (int i = 1; i < n; i++)
    {
        int preIndex = i - 1;
        int cur = a[i];
        while (preIndex >= 0 && a[preIndex] > cur)
        {
            a[preIndex + 1] = a[preIndex];
            preIndex--;
        }
        a[preIndex + 1] = cur;
    }
}
//希尔排序
void ShellSort(int a[], int t)
{
    int i;
    for (i = 1; i <= t; i++)
    {
        int dk = (int)(pow(2, t - i + 1) - 1); //使用Hibbard增量
        int j, k, temp;
        for (j = dk; j < n; j++) //分别向每组的有序区域插入
        {
            temp = a[j];
            for (k = j - dk; (k >= j % dk) && a[k] > temp; k -= dk) //比较与记录后移同时进行
                a[k + dk] = a[k];
            if (k != j - dk)
                a[k + dk] = temp; //插入
        }
    }
}
void merge(int arr[], int l, int mid, int r)
{
    int help[r - l + 1]; //辅助数组
    int i = 0;
    int lIndex = l;
    int rIndex = mid + 1;
    while (lIndex <= mid && rIndex <= r)
    {
        help[i++] = ((arr[lIndex] < arr[rIndex]) ? arr[lIndex++] : arr[rIndex++]);
    }
    while (lIndex <= mid)
    {
        help[i++] = arr[lIndex++];
    }
    while (rIndex <= r)
    {
        help[i++] = arr[rIndex++];
    }
    for (i = 0; i < r - l + 1; i++)
    {
        arr[l + i] = help[i];
    }
}
static void mergeSort(int arr[], int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    //左半部分归并排序
    mergeSort(arr, l, mid);
    //右半部分归并排序
    mergeSort(arr, mid + 1, r);
    //左右部分归并
    merge(arr, l, mid, r);
}
void mergeSort(int arr[], int n)
{
    if (arr == NULL || n < 2)
    {
        return;
    }
    mergeSort(arr, 0, n - 1);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    //Bubble(a);
    //Insert(a);
    //ShellSort(a, (int)(log(n + 1) / log(2)));
    mergeSort(a, n);
    Print(a);
    return 0;
}