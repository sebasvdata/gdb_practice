#include <stdio.h>
#include <string.h>

static char *ft_strcpy(char *dst, const char *src)
{
	size_t i = 0;

	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int main(void)
{
	char dst[64];

	memset(dst, '.', sizeof(dst));
	dst[sizeof(dst) - 1] = '\0';
	printf("Copia: [%s]\n", ft_strcpy(dst, "debug"));
	return (0);
}
