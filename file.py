import os

def valid(n):
    n = int(n)
    result = 0
    
    if n % 10 == 0:
        result = n / 10
        return (round(result), 10)
    elif n % 2 == 0:
        result = n / 2
        return (round(result), 2)
    

def main():
    file = open("123.txt", "r")
    for line in file:
        number = line.strip('\n')
        n = valid(number)
        print(f"{number} = {n[0]} * {n[1]}")
    file.close()
main()
