#include <stdio.h>

static int max(int *tab, unsigned int len)
{
	unsigned int i;
	int best = 0;

	i = 0;
	while (i < len)
	{
		if (tab[i] > best)
			best = tab[i];
		i++;
	}
	return (best);
}

int main(void)
{
	int values[] = {-8, -3, -12, -5};

	printf("Maximo: %d\n", max(values, sizeof(values) / sizeof(values[0])));
	return (0);
}
