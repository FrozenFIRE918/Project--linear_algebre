/*
#include<stdio.h>
#include<stdlib.h>

int n=2;

long long Factorial(int n)              //计算1-n个自然数的排列方式的总数
{
	int i;
	long long product = 1;

	for (i = 1; i <= n; i++)
		product = product * i;

	return product;
}

long Evaluate_determinant(int input[], int c_subscript[])
{
	long sum = 0, SUM = 0;
	int column = 0;

	for (int i = 1; i <= Factorial(n); i++)
	{
		int product = 1, symbol = 1;

		for (int count = 0; count < n; count++)
		{
			column = c_subscript[(i - 1) * n + count + 1];
			printf("c%d=%d\n", column,input[column-1]);

			product = product * input[count*n+column-1];
			for (int c = count+1; c < n; c++)
			{
				int nextcolumn = c_subscript[(i - 1) * n + count + 2];
				printf("next column =%d\n", nextcolumn);
				if (column > nextcolumn)
					symbol *= -1;
			}
		}
		product *= symbol;
		printf("product=%d", product);
		SUM += product;
		printf("SUM=%d", SUM);
	}
	return SUM;
}

int main(void)
{
	int input[4] = { 1,2,2,1 };
	int c_subscript[5] = { 0,1,2,2,1 };

	printf("%d", Evaluate_determinant(input, c_subscript));
	return 0;
}
*/