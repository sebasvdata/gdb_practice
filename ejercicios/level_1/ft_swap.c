#include <stdio.h>

static void ft_swap(int *a, int *b)
{
	*a = *b;
	*b = *a;
}

int main(void)
{
	int a = 3;
	int b = 7;

	printf("Antes: a = %d, b = %d\n", a, b);
	ft_swap(&a, &b);
	printf("Despues: a = %d, b = %d\n", a, b);
	return (0);
}
