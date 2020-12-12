/*
 * @Author: Whx
 * @Date: 2020-11-20 21:42:10
 * @LastEditTime: 2020-11-20 22:23:58
 */
#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <string>
#define CEHUA 0
#define MEISHU 1
#define YANFA 2
using namespace std;
class Worker
{
public:
    string m_Name;
    int m_salary;
};
void createWorker(vector<Worker> &v)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];
        worker.m_salary = rand() % 10000 + 10000; //10000~19999
        v.push_back(worker);
    }
}
void setGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        int deptId = rand() % 3;
        m.insert(make_pair(deptId, *it));
    }
}
void showWorkerByGroup(multimap<int, Worker> &m)
{
    cout << "策划部门:" << endl;
    multimap<int, Worker>::iterator pos = m.find(CEHUA);
    int cnt = m.count(CEHUA);
    int i = 0;
    for (; pos != m.end() && i < cnt; pos++, i++)
    {
        cout << "姓名: " << pos->second.m_Name << " 工资：" << pos->second.m_salary << endl;
    }

    cout << "-----------------" << endl;
    cout << "美术部门:" << endl;
    pos = m.find(MEISHU);
    cnt = m.count(MEISHU);
    i = 0;
    for (; pos != m.end() && i < cnt; pos++, i++)
    {
        cout << "姓名: " << pos->second.m_Name << " 工资：" << pos->second.m_salary << endl;
    }

    cout << "-----------------" << endl;
    cout << "研发部门:" << endl;
    pos = m.find(YANFA);
    cnt = m.count(YANFA);
    i = 0;
    for (; pos != m.end() && i < cnt; pos++, i++)
    {
        cout << "姓名: " << pos->second.m_Name << " 工资：" << pos->second.m_salary << endl;
    }
}
int main()
{
    srand((unsigned int)time(NULL));
    vector<Worker> vWorker;
    createWorker(vWorker);
    multimap<int, Worker> mWorker;
    setGroup(vWorker, mWorker);
    showWorkerByGroup(mWorker);
    return 0;
}