/*
��������a������a[i]��ʾ���һ��i�㺺ŵ���ƶ��Ĵ�����
ָ��o,p,q�ֱ��ʾ����λ�á�
��ʼ״̬Ϊn�㶼��o�ϣ�Ҫ��q�����ƶ���
Ȼ��ֳ����������
1��
m<=a[n-1];
��ʱ����n��û�����ƶ�����ô���൱��o�ϵ�n-1����p���ƶ���
ʹ��״̬����ʼ״̬һ�£�����Ҫ����p��q��
2��
m>a[n-1];
��ʱ���Ƚ��е�����״̬������n-1���ƶ���pλ�ã���n���ƶ���qλ�ã�������a[n-1]+1���ƶ���
�������ͱ��p�ϵ�n-1����q���ƶ���ֻҪ����o,p����m=m-a[n-1]-1���ɡ�
ͨ�����������������Եõ���n���λ�ã�����������n-1�㶼��o�ϣ�Ҫ��q�����ƶ���
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	unsigned long long m, a[65];
	int row[3][65];
	a[0] = 0;
	a[1] = 1;
	for (int i = 2; i <= 63; i++)
		a[i] = a[i - 1] * 2 + 1;
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n >> m;
		int* start, * mid, * end;
		start = row[0];
		mid = row[1];
		end = row[2];
		*start = *mid = *end = 1;
		while (n)							//�ݹ���ΰ��...
		{
			n--;
			if (m <= a[n])
			{
				*(start + *start) = n + 1;	//�ѿ�ʼλ�õ����һλ�̶�
				(*start)++;					//��ʼλ�ö�һ������
				swap(end, mid);				//����������,�´εݹ�ͻ�����ӻ����м�
			}
			else
			{
				*(end + *end) = n + 1;		//��endλ�����һ���Ӹ�����
				(*end)++;					//endλ�õ���������һ
				swap(start, mid);			//����ǰ����,�൱�ڰ�n-1�����Ӵ�start->mid,����������a[n-1]��
				m = m - a[n] - 1;			//�˹���һ������a[n-1]+1��,����ǰ��n--��,���������ȥa[n]
			}
		}
		for (int i = 0; i < 3; i++)
		{
			cout << row[i][0] - 1;
			for (int j = 1; j < row[i][0]; j++)
				cout << ' ' << row[i][j];
			cout << endl;
		}
	}
	return 0;
}