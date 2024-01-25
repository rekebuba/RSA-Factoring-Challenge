#include <stdio.h>
#include <string.h>
#include <stdlib.h>
ssize_t getline(char **lineptr, size_t *n, FILE *file);

/**
 * main - Factorize as many numbers as possible into
 * a product of two smaller numbers.
 * @argc: command line counter
 * @argv: argument
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	ssize_t read;
	size_t len = 0;
	char *buffer = NULL;
	FILE *file = fopen(argv[1], "r");
	long unsigned int num, i;

	if (argc == 2 && *argv)
	{
		while ((read = getline(&buffer, &len, file)) != -1)
		{
			buffer[strlen(buffer) - 1] = '\0';
			if (strlen(buffer) < 20)
			{
				num = atol(buffer);
				for (i = 2; num % i != 0; i++)
					;
				printf("%lu=%lu*%lu\n", num, (num / i), i);
			}
		}
	}
	return (0);
}
