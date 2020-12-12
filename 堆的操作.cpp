/*
 * @Author: Whx
 * @Date: 2020-11-17 20:37:05
 * @LastEditTime: 2020-11-19 23:23:46
 */
#include <iostream>
using namespace std;
struct heap
{
    int data[1001];
    int size;
    int capacity;
    heap(int cap)
    {
        size = 0;
        capacity = cap;
    }
};
typedef struct heap *Heap;
void percolateUp(Heap h, int index) //将h[index]元素往上移
{
    int i, tmp = h->data[index];
    for (i = index; i / 2 > 0 && tmp < h->data[i / 2]; i /= 2)
        h->data[i] = h->data[i / 2];
    h->data[i] = tmp;
}
void percolateDown(Heap h, int index) //将h[index]元素往下移
{
    int i, tmp = h->data[index], child;
    for (i = index; i * 2 <= h->size; i = child)
    {
        child = i * 2;
        if (child < h->size && h->data[child + 1] < h->data[child])
            child++;
        if (tmp > h->data[child])
            h->data[i] = h->data[child];
        else
            break;
    }
    h->data[i] = tmp;
}
void insert(Heap h, int key)
{
    if (h->size == h->capacity)
        return;
    h->data[++h->size] = key;
    percolateUp(h, h->size);
}
void remove(Heap h)
{
    if (h->size == 0)
        return;
    h->data[1] = h->data[h->size--];
    percolateDown(h, 1);
}
void print(Heap h)
{
    for (int i = 1; i < h->size; i++)
        cout << h->data[i] << ' ';
    cout << h->data[h->size] << endl;
}
int main()
{
    int N, K, M;
    int tmp;
    cin >> N >> K;
    Heap h = new heap(N);
    for (int i = 0; i < K; i++)
    {
        cin >> tmp;
        if (tmp == 1)
        {
            cin >> tmp;
            insert(h, tmp);
        }
        else
        {
            remove(h);
        }
        print(h);
    }
    cin >> M;
    Heap h2 = new heap(1001);
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        h2->data[++h2->size] = tmp;
    }
    for (int i = h2->size / 2; i > 0; i--)
        percolateDown(h2, i);
    print(h2);
    return 0;
}