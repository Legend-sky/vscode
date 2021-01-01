/*
 * @Author: Whx
 * @Date: 2020-12-31 21:12:38
 * @LastEditTime: 2020-12-31 22:52:24
 */
#include <cstdio>
#include <stdlib.h>
typedef struct student
{
    char name[10], id[10];
    int gender;
    int age;
    double scored;
} ST;
ST *s = (ST *)malloc(sizeof(ST));
ST *s = new ST();
// struct student
// {
//     char name[10], id[10];
//     int gender;
//     int age;
//     double scored;
// };
// struct student *stu;
void output(ST *d, FILE *fout)
{
    if (d == NULL)
    {
        printf("null\n");
        return;
    }
    fprintf(fout, "%s,%s,%d,%d,%4.2f\n", d->name, d->id, d->gender, d->age, d->scored);
}
void fun(FILE *fin, FILE *fout)
{
    ST *stu;
    stu = (ST *)malloc(sizeof(ST)); //指针没有内存，要分配一个内存才行！
    while (fscanf(fin, "%s%s%d%d%lf\n", &stu->name, &stu->id, &stu->gender, &stu->age, &stu->scored) != EOF)
    {
        output(stu, fout);
    }
    return;
}
int main()
{
    FILE *fp, *fo;
    fp = fopen("d:\\input.txt", "r");
    fo = fopen("d:\\output.txt", "w");
    fun(fp, fo);
    fclose(fp);
    fclose(fo);
    return 0;
}