//���޽�����ʽ��ֵ�㷨V0.2.0
//���ߣ���_��

#include<stdio.h>
#include<stdlib.h>

//����ԭ��
void swap(int*, int*);
void perm(int list[], int*, int, int,int);
long long Factorial(int n);
long Evaluate_determinant(int input[], int c_subscript[],int n);

int count = 0;                            //count������ȫ���е�����
int n = 0;                                  //n������¼����ʽ����

int main(void)
{
	system("color 70");
	int n=0,decision=0;

	printf("|��ã���ӭʹ���������޽�����ʽ��������|\n");
	printf("|ʹ�÷�����ÿ����һ�����־Ͱ�һ�»س���|\n\n");
	
	do {
		printf("|��������Ҫ��ֵ������ʽ�Ľ�����");

		scanf_s("%d", &n);

		long long a = Factorial(n);
		//printf("a=%lld", a);
		int* input;
		input = (int*)malloc(n * n * sizeof(int));
		//printf("size_input=%d  ", n * n * sizeof(int));

		int* factorial;
		factorial = (int*)malloc(n * sizeof(int));
		//printf("size_factorial=%d  ", n * sizeof(int));

		int* c_subscript = 0;                       //�������ڴ洢�б�ȫ���еĶ�̬����c_subscription
		c_subscript = (int*)malloc(((a * n) + 1) * sizeof(int));                   //��������ʽ�Ľ���Ϊ���������ڴ�ռ�
		//printf("size_c_subscript=%lld  ", ((a * n) + 1) * sizeof(int));

		//printf("%d", sizeof(int));
		printf("|�����밴��ʾ��������ʽ��Ԫ��|\n");
		for (int i1 = 0; i1 < n; i1++)
		{
			printf("|�����������%d�е�%d��Ԫ��|\n", i1 + 1, n);
			for (int i2 = 0; i2 < n; i2++)
			{
				scanf_s("%d", (input + i1 * n + i2));
			}
		}

		for (int fac = 1; fac <= n; fac++)
		{
			factorial[fac - 1] = fac;
			//printf("fac=%d\n", factorial[fac-1]);
		}
		perm(factorial, c_subscript, 0, n - 1, n);
		free(factorial);

		/*for (int i = 1; i <= (Factorial(n) * n); i++)                   //��ѭ����������ȡ�б�
		{
			printf("c_sub=%d\n", c_subscript[i]);
			printf("c_sub=%p\n", &c_subscript[i]);
			if (i % n == 0)
				putchar('\n');
		}*/

		printf("������ʽ��ֵ=%d\n", Evaluate_determinant(input, c_subscript, n));

		free(input);
		free(c_subscript);

		printf("|������ɣ��������ʹ���밴�س����������˳������밴q��|\n");
		decision = getch();
	} while (decision !=81&&decision!=113 );
	system("exit");
	return 0;
}

void swap(int* a, int* b)           //����������������ֵ�ĺ���
{
	int m;
	m = *a;
	*a = *b;
	*b = m;
}

void perm(int list[], int* ptr, int begin, int end,int n)      //����list[begin:end]����������
{
	int i;

	if (begin == end)        //begin����end����list��ֻ��һ��Ԫ��ʱ
	{
		for (i = 1; i <= begin + 1; i++)
		{
			ptr[ i + count * n] = list[i - 1];             //������list�д洢������ͨ��ָ�봩͸�ںд�����������������c_subscript
			//printf("#%d\n", list[i - 1]);							//�������list�е��������ڳ������
			//printf("forѭ���ڵ�count=%d\n",  count );
			//printf("i+count*n=%d\n", i + count * n);
			//printf("ptr=%d\n", ptr[i + count * n]);
			//printf("ptr=%p\n", &ptr[i + count * n]);
		}

		count++;                 //count�ĸ�����һ����ʾ����һ�����������
		//printf("count=%d\n", count);
	}
	else
	{
		for (i = begin; i <= end; i++)       //���ж��Ԫ�ش����У����β���:3�������{5,8,2}��ȫ����+5�������{3,8,2}��ȫ����+8�������{3,5,2}��ȫ����+2�������{3,5,8}��ȫ���� 
		{
			swap(&list[begin], &list[i]);
			perm(list, ptr, begin + 1, end,n);
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

long Evaluate_determinant(int *input, int *c_subscript,int n)
{
	long sum = 0, SUM = 0;
	int column = 0;
	//printf("��ֵ������n=%d", n);
	for (int i = 1; i <= Factorial(n); i++)
	{
		int product = 1, symbol = 1;

		for (int count = 0; count < n; count++)
		{
			column = c_subscript[(i - 1) * n + count + 1];
			//printf("\nc%d=%d\n", column, input[count*n+column - 1]);
			
			product = product * input[count * n + column - 1];
			for (int c = count + 1; c < n; c++)	
				//���б�������
			{
				int nextcolumn = c_subscript[(i - 1) * n + c + 1];
				//printf("next column =%d\n", nextcolumn);
				if (column > nextcolumn)
					symbol *= -1;
			}
		}
		product *= symbol;
		//printf("product=%d", product);
		SUM += product;
		//printf("SUM=%d", SUM);
	}
	return SUM;
}

//�����ȫ���к���permʱ�������ĵݹ�˼·�ο���CSDN�û� ����������121�� �Ĳ��ͣ� https://blog.csdn.net/weixin_40202230/article/details/78003317?utm_term=c%E8%AF%AD%E8%A8%80%E5%85%A8%E6%8E%92%E5%88%97%E5%87%BD%E6%95%B0&utm_medium=distribute.pc_aggpage_search_result.none-task-blog-2~all~sobaiduweb~default-4-78003317&spm=3001.4430