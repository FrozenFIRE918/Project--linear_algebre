/*
#include <stdio.h> 
#include<stdlib.h>

int count = 0;                            //count������ȫ���е�����
int n = 0;                                  //n������¼����ʽ����

//����ԭ��
void swap(int*, int*);
void perm(int list[],int *, int, int);
long long Factorial(int n);

int main()                         //������
{
    int input[] = { 1,2};                 //�����������滻Ϊ����input
  
    scanf_s("%d", &n);
    long long a = Factorial(n);
    //printf("%d", a);                  //���0-n�����з�ʽ���������ڲ���

    int* c_subscript=0;                       //�������ڴ洢�б�ȫ���еĶ�̬����c_subscription
    c_subscript = (int*)malloc(((a * n )+1)* sizeof(int));                   //��������ʽ�Ľ���Ϊ���������ڴ�ռ�

    perm(input,c_subscript, 0, n-1);
    for (int i = 1; i <=( Factorial(n) * n); i++)                   //��ѭ����������ȡ�б�
    {
        printf("%d ", c_subscript[i]);
        if (i % n == 0)
            putchar('\n');
    }
    
    free(c_subscript);                   //���c_subscriptionռ�õ��ڴ棬��ֹ�ڴ����

    return 0;
}


void swap(int* a, int* b)           //����������������ֵ�ĺ���
{
    int m;
    m = *a;
    *a = *b;
    *b = m;
}

void perm(int list[],int *ptr,int begin, int end)      //����list[begin:end]����������
{
    int i;
    if (begin == end)        //begin����end����list��ֻ��һ��Ԫ��ʱ
    {
        for (i = 1; i <= begin + 1; i++)
        {
            *(ptr + i + count * n) = list[i-1];             //������list�д洢������ͨ��ָ�봩͸�ںд�����������������c_subscript
            //printf("#%d", list[i - 1]);               //�������list�е��������ڳ������
        }
           
         count++;                 //count�ĸ�����һ����ʾ����һ�����������
    }
    else
    {
        for (i = begin; i <= end; i++)       //���ж��Ԫ�ش����У����β���:3�������{5,8,2}��ȫ����+5�������{3,8,2}��ȫ����+8�������{3,5,2}��ȫ����+2�������{3,5,8}��ȫ���� 
        {
            swap(&list[begin], &list[i]);
            perm(list, ptr,begin + 1, end);
            swap(&list[begin], &list[i]);
        }
    }
}

long long Factorial(int n)              //����1-n����Ȼ�������з�ʽ������
{
    int i;
    long long product = 1;

    for (i = 1; i <= n; i++)
        product = product * i;

    return product;
}
*/
