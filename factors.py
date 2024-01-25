#!/usr/bin/python3
import sys


def main():
    try:
        file = open(sys.argv[1], "r")
    except FileNotFoundError:
        exit()
    for line in file:
        number = int(line.strip('\n'))
        a = 2
        while True:
            if number % a == 0:
                break
            a += 1
        
        print(f"{number}={round(number / a)}*{a}")
    file.close()
main()
