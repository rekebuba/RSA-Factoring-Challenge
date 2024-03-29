#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Factorize as many numbers as possible
 * into a product of two smaller numbers.
 * @argc: argument count
 * @argv: argument passed
 * Return: int
 */
int main(int argc, char **argv)
{
	FILE *file = fopen(argv[1], "r");
	if (!file || argc != 2)
	{
		return 1;
	}
	ssize_t read;
	size_t n = 0;
	unsigned long int num, i;
	char *buffer = NULL, *endptr;

	while ((read = getline(&buffer, &n, file)) != -1)
	{
		buffer[strlen(buffer) - 1] = '\0';
		if (strlen(buffer) < 20)
		{
			num = strtoul(buffer, &endptr, 10);

			for (i = 2; num % i != 0; i++)
				;
			printf("%lu=%lu*%lu\n", num, num / i, i);
		}
	}

	fclose(file);
	free(buffer);
	return (0);
}
