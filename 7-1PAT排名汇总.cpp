/*
 * @Author: Whx
 * @Date: 2021-01-09 19:33:53
 * @LastEditTime: 2021-01-09 20:17:53
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define ll long long

using namespace std;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;
struct stu
{
    char name[15];
    int score;
    int zmc;    //总名次
    int num;    //考点编号
    int num_mc; //在该考点的名次
} students[30005];
bool cmp(stu a, stu b)
{
    if (a.score == b.score)
        return a.name < b.name;
    return a.score > b.score;
}
int main()
{
    int number;     //考场个数
    int peo = 0;    //总人数
    int k = 0;      //总人数
    int number_num; //考场里有几个人
    cin >> number;
    for (int i = 1; i <= number; i++)
    {
        cin >> number_num;
        k += number_num;
        for (int j = 1; j <= number_num; j++)
        {
            cin >> students[++peo].name >> students[peo].score;
            students[peo].num = i;
        }
        sort(students + 1 + k - number_num, students + 1 + k, cmp);
        int q = 2;
        students[k + 1 - number_num].num_mc = 1;
        for (int j = k + 2 - number_num; j <= k; j++, q++)
        {
            if (students[j].score == students[j - 1].score)
            {
                students[j].num_mc = students[j - 1].num_mc;
            }
            else
            {
                students[j].num_mc = q;
            }
        }
    }
    sort(students + 1, students + 1 + k, cmp);
    int u = 2;
    students[1].zmc = 1;
    for (int i = 2; i <= k; i++, u++)
    {
        if (students[i].score == students[i - 1].score)
        {
            students[i].zmc = students[i - 1].zmc;
        }
        else
        {
            students[i].zmc = u;
        }
    }
    cout << k << endl;
    for (int i = 1; i <= k; i++)
    {
        cout << students[i].name << " " << students[i].zmc << " " << students[i].num << " " << students[i].num_mc << endl;
    }
    return 0;
}
/*
 * @Author: Whx
 * @Date: 2021-01-09 19:33:53
 * @LastEditTime: 2021-01-09 20:13:16
 */
/*
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define ll long long

using namespace std;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7;
struct PTA
{
	int place;
	int score;
	string num;
	int rank_in_palce;
	int rank_total;	
}b[30001];
bool cmp1(PTA x,PTA y)
{
	if(x.score==y.score)
		return x.num<y.num;
	return x.score>y.score;
}
int main()
{
	int N,total=0;
	cin>>N;
	int i=1,j=0,z=0;
	for(i=0;i<N;i++)
	{
		int Ki;
		cin>>Ki;
		for( j=0;j<Ki;j++){
			b[total].place=i+1;
			cin>>b[total].num>>b[total].score;
			total++;
		}
		sort(b+z,b+z+Ki,cmp1);
		int m=1;
		b[z].rank_in_palce=m;
		m++;
		for(j=z+1;j<z+Ki;j++){
			if(b[j].score<b[j-1].score){
				b[j].rank_in_palce=m;
				m++;
			}
			else{
				b[j].rank_in_palce=b[j-1].rank_in_palce;	
				m++;
			}
		}
		z=total;
	}
	sort(b,b+total,cmp1);
	int m=1;
	b[0].rank_total=m;
	m++;
	for(j=1;j<total;j++){
		if(b[j].score<b[j-1].score){
			b[j].rank_total=m;
			m++;
		}
		else{
			b[j].rank_total=b[j-1].rank_total;	 
			m++;
		}
	}
	cout<<total<<endl;
	for(i=0;i<total;i++)
		cout<<b[i].num<<" "<<b[i].rank_total<<" "<<b[i].place<<" "<<b[i].rank_in_palce<<endl;
	return 0;
}
*/