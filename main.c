#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char **argv)
{
    mpz_t num;
    FILE *file = fopen(argv[1], "r");
    ssize_t read;
    ssize_t n = 0;
    char *endptr;
    mpz_init(num);
    char *buffer = NULL;
    while (read = getline(&buffer, &n, file) != -1)
    {
        buffer[strlen(buffer) - 1] = '\0';
        mpz_set_str(num, buffer, 10);
        printf("%li\n", num);
    }

    return (0);
}
