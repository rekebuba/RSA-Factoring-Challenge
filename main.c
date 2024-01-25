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
	ssize_t read, n = 0;
	unsigned long long int num, i;
	char *buffer = NULL, *endptr;

	if (argc == 2 && *argv)
	{
		while (read = getline(&buffer, &n, file) != -1)
		{
			buffer[strlen(buffer) - 1] = '\0';
			num = strtoull(buffer, &endptr, 10);

			for (i = 2; num % i != 0; i++)
				;
			printf("%lli=%lli*%lli\n", num, num / i, i);
		}
	}

	return (0);
}
