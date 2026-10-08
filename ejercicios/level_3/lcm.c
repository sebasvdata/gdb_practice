#include <stdio.h>

static int gcd(int a, int b)
{
	int remainder;

	while (b != 0)
	{
		a = b;
		remainder = a % b;
		b = remainder;
	}
	return (a);
}

static int lcm(int a, int b)
{
	return ((a / gcd(a, b)) * b);
}

int main(void)
{
	int a = 12;
	int b = 18;

	printf("MCM de %d y %d: %d\n", a, b, lcm(a, b));
	return (0);
}
