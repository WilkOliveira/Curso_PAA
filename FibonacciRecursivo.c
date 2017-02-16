#include<stdio.h>

int fibonacci(int n)
{
	if (n==1 || n==0)
	{
		return n;
	}
	else
	{
		return (fibonacci(n-1)+fibonacci(n-2));
	}
}

int main()
{
	int x;
	printf("Digite um numero\n");
	scanf("%d",&x);
	printf("O fibonacci de %d é: %d\n",x, fibonacci(x));

	return 0;
}
