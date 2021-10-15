//有限阶行列式求值算法V0.2.0
//作者：静_火

#include<stdio.h>
#include<stdlib.h>

//函数原型
void swap(int*, int*);
void perm(int list[], int*, int, int,int);
long long Factorial(int n);
long Evaluate_determinant(int input[], int c_subscript[],int n);

int count = 0;                            //count用来计全排列的总数
int n = 0;                                  //n用来记录行列式阶数

int main(void)
{
	system("color 70");
	int n=0,decision=0;

	printf("|你好，欢迎使用任意有限阶行列式计算器！|\n");
	printf("|使用方法：每输入一个数字就按一下回车键|\n\n");
	
	do {
		printf("|请输入想要求值的行列式的阶数：");

		scanf_s("%d", &n);

		long long a = Factorial(n);
		//printf("a=%lld", a);
		int* input;
		input = (int*)malloc(n * n * sizeof(int));
		//printf("size_input=%d  ", n * n * sizeof(int));

		int* factorial;
		factorial = (int*)malloc(n * sizeof(int));
		//printf("size_factorial=%d  ", n * sizeof(int));

		int* c_subscript = 0;                       //声明用于存储列标全排列的动态数组c_subscription
		c_subscript = (int*)malloc(((a * n) + 1) * sizeof(int));                   //根据行列式的阶数为数组申请内存空间
		//printf("size_c_subscript=%lld  ", ((a * n) + 1) * sizeof(int));

		//printf("%d", sizeof(int));
		printf("|下面请按提示输入行列式的元素|\n");
		for (int i1 = 0; i1 < n; i1++)
		{
			printf("|请依次输入第%d行的%d个元素|\n", i1 + 1, n);
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

		/*for (int i = 1; i <= (Factorial(n) * n); i++)                   //此循环将用于提取列标
		{
			printf("c_sub=%d\n", c_subscript[i]);
			printf("c_sub=%p\n", &c_subscript[i]);
			if (i % n == 0)
				putchar('\n');
		}*/

		printf("该行列式的值=%d\n", Evaluate_determinant(input, c_subscript, n));

		free(input);
		free(c_subscript);

		printf("|计算完成，如想继续使用请按回车键，如想退出程序请按q键|\n");
		decision = getch();
	} while (decision !=81&&decision!=113 );
	system("exit");
	return 0;
}

void swap(int* a, int* b)           //用来交换两个变量值的函数
{
	int m;
	m = *a;
	*a = *b;
	*b = m;
}

void perm(int list[], int* ptr, int begin, int end,int n)      //产生list[begin:end]的所有排列
{
	int i;

	if (begin == end)        //begin等于end，即list中只有一个元素时
	{
		for (i = 1; i <= begin + 1; i++)
		{
			ptr[ i + count * n] = list[i - 1];             //将数组list中存储的排列通过指针穿透黑盒传输给主函数里的数组c_subscript
			//printf("#%d\n", list[i - 1]);							//用于输出list中的数，用于程序测试
			//printf("for循环内的count=%d\n",  count );
			//printf("i+count*n=%d\n", i + count * n);
			//printf("ptr=%d\n", ptr[i + count * n]);
			//printf("ptr=%p\n", &ptr[i + count * n]);
		}

		count++;                 //count的个数加一，表示又有一种情况产生了
		//printf("count=%d\n", count);
	}
	else
	{
		for (i = begin; i <= end; i++)       //还有多个元素待排列，依次产生:3后面跟着{5,8,2}的全排列+5后面跟着{3,8,2}的全排列+8后面跟着{3,5,2}的全排列+2后面跟着{3,5,8}的全排列 
		{
			swap(&list[begin], &list[i]);
			perm(list, ptr, begin + 1, end,n);
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

long Evaluate_determinant(int *input, int *c_subscript,int n)
{
	long sum = 0, SUM = 0;
	int column = 0;
	//printf("求值函数内n=%d", n);
	for (int i = 1; i <= Factorial(n); i++)
	{
		int product = 1, symbol = 1;

		for (int count = 0; count < n; count++)
		{
			column = c_subscript[(i - 1) * n + count + 1];
			//printf("\nc%d=%d\n", column, input[count*n+column - 1]);
			
			product = product * input[count * n + column - 1];
			for (int c = count + 1; c < n; c++)	
				//求列标逆序数
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

//在设计全排列函数perm时，函数的递归思路参考了CSDN用户 “晶晶姑娘121” 的博客： https://blog.csdn.net/weixin_40202230/article/details/78003317?utm_term=c%E8%AF%AD%E8%A8%80%E5%85%A8%E6%8E%92%E5%88%97%E5%87%BD%E6%95%B0&utm_medium=distribute.pc_aggpage_search_result.none-task-blog-2~all~sobaiduweb~default-4-78003317&spm=3001.4430