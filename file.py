import os

def valid(n):
    n = int(n)
    result = 0
    if n % 2 == 0:
        result = n / 2
    return result

def main():
    file = open("123.txt", "r")
    for line in file:
        number = line.strip('\n')
        n = valid(number)
        print(f"{number} = {n} * {2}")
    file.close()
main()
