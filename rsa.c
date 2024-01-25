#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_prime(unsigned long int num);
bool are_both_primes(unsigned long int num1, unsigned long int num2);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
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

            for (i = 2; i <= num / 2; i++)
            {
                if (num % i == 0 && are_both_primes(i, (num / i)))
                {
                    printf("%lu=%lu*%lu\n", num, (num / i), i);
                    break;
                }
            }          
        }
    }
    fclose(file);
    free(buffer);
    return (0);
}


bool is_prime(unsigned long int num)
{
    for (unsigned long int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

bool are_both_primes(unsigned long int num1, unsigned long int num2)
{
    return is_prime(num1) && is_prime(num2);
}
