#include <stdio.h>
#include <string.h>

static char *ft_strrev(char *text)
{
	int left = 0;
	int right = (int)strlen(text) - 1;
	char tmp;

	while (left < right - 1)
	{
		tmp = text[left];
		text[left] = text[right];
		text[right] = tmp;
		left++;
		right--;
	}
	return (text);
}

int main(void)
{
	char text[] = "gdb!";

	printf("Invertida: %s\n", ft_strrev(text));
	return (0);
}
