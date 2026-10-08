#include <stdio.h>

static void last_word(const char *text)
{
	int end = 0;
	int start;
	int word_end;

	while (text[end] != '\0')
		end++;
	start = end;
	while (start > 0 && text[start - 1] == ' ')
		start--;
	word_end = start;
	while (start > 0 && text[start - 1] != ' ')
		start--;
	while (start < word_end - 1)
		putchar(text[start++]);
	putchar('\n');
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Uso: %s \"cadena\"\n", argv[0]);
		return (1);
	}
	last_word(argv[1]);
	return (0);
}
