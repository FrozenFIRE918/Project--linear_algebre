/*
#include <stdio.h> 
#include<stdlib.h>

int count = 0;                            //count用来计全排列的总数
int n = 0;                                  //n用来记录行列式阶数

//函数原型
void swap(int*, int*);
void perm(int list[],int *, int, int);
long long Factorial(int n);

int main()                         //主函数
{
    int input[] = { 1,2};                 //在主程序中替换为数组input
  
    scanf_s("%d", &n);
    long long a = Factorial(n);
    //printf("%d", a);                  //输出0-n的排列方式总数，用于测试

    int* c_subscript=0;                       //声明用于存储列标全排列的动态数组c_subscription
    c_subscript = (int*)malloc(((a * n )+1)* sizeof(int));                   //根据行列式的阶数为数组申请内存空间

    perm(input,c_subscript, 0, n-1);
    for (int i = 1; i <=( Factorial(n) * n); i++)                   //此循环将用于提取列标
    {
        printf("%d ", c_subscript[i]);
        if (i % n == 0)
            putchar('\n');
    }
    
    free(c_subscript);                   //清空c_subscription占用的内存，防止内存溢出

    return 0;
}


void swap(int* a, int* b)           //用来交换两个变量值的函数
{
    int m;
    m = *a;
    *a = *b;
    *b = m;
}

void perm(int list[],int *ptr,int begin, int end)      //产生list[begin:end]的所有排列
{
    int i;
    if (begin == end)        //begin等于end，即list中只有一个元素时
    {
        for (i = 1; i <= begin + 1; i++)
        {
            *(ptr + i + count * n) = list[i-1];             //将数组list中存储的排列通过指针穿透黑盒传输给主函数里的数组c_subscript
            //printf("#%d", list[i - 1]);               //用于输出list中的数，用于程序测试
        }
           
         count++;                 //count的个数加一，表示又有一种情况产生了
    }
    else
    {
        for (i = begin; i <= end; i++)       //还有多个元素待排列，依次产生:3后面跟着{5,8,2}的全排列+5后面跟着{3,8,2}的全排列+8后面跟着{3,5,2}的全排列+2后面跟着{3,5,8}的全排列 
        {
            swap(&list[begin], &list[i]);
            perm(list, ptr,begin + 1, end);
            swap(&list[begin], &list[i]);
        }
    }
}

long long Factorial(int n)              //计算1-n个自然数的排列方式的总数
{
    int i;
    long long product = 1;

    for (i = 1; i <= n; i++)
        product = product * i;

    return product;
}
*/
