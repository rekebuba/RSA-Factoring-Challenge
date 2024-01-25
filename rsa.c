#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

bool miller_rabin(unsigned long long int num, int k);
unsigned long long int power(unsigned long long int x, unsigned long long int y, unsigned long long int p);
bool is_prime(unsigned long long int num);
bool are_both_primes(unsigned long long int num1, unsigned long long int num2);

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
    unsigned long long int num, i;
    char *buffer = NULL, *endptr;
    while ((read = getline(&buffer, &n, file)) != -1)
    {
        buffer[strlen(buffer) - 1] = '\0';
        if (strlen(buffer) < 20)
        {
            num = strtoll(buffer, &endptr, 10);

            for (i = 2; i <= num / 2; i++)
            {
                if (num % i == 0 && are_both_primes((num / i), i))
                {
                    printf("%llu=%llu*%llu\n", num, (num / i), i);
                    break;
                }
            }
        }
    }
    fclose(file);
    free(buffer);
    return (0);
}

/**
 * is_prime - check if a number is prime
 *
 * @num: the number
 * Return: true or false
 */
bool is_prime(unsigned long long int num)
{
    for (unsigned long long int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

/**
 * is_prime - check if a number is prime
 *
 * @num1: the first number
 * @num2: the second number
 * Return: true or false
 */
bool are_both_primes(unsigned long long int num1, unsigned long long int num2)
{
    return miller_rabin(num1, 5) && miller_rabin(num2, 5);
}
unsigned long long int power(unsigned long long int x, unsigned long long int y, unsigned long long int p)
{
    unsigned long long int res = 1;
    x = x % p;

    while (y > 0)
    {
        if (y & 1)
        {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }

    return res;
}

bool miller_rabin(unsigned long long int num, int k)
{
    if (num <= 1 || num == 4)
    {
        return false;
    }
    if (num <= 3)
    {
        return true;
    }

    unsigned long long int d = num - 1;
    while (d % 2 == 0)
    {
        d /= 2;
    }

    for (int i = 0; i < k; i++)
    {
        unsigned long long int a = 2 + rand() % (num - 4);
        unsigned long long int x = power(a, d, num);

        if (x == 1 || x == num - 1)
        {
            continue;
        }

        int flag = 0;
        while (d != num - 1)
        {
            x = (x * x) % num;
            d *= 2;

            if (x == 1)
            {
                return false;
            }
            if (x == num - 1)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            return false;
        }
        printf("%lli\n", d);
    }

    return true;
}
