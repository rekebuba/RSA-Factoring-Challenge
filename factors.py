import sys


def main():
    file = open(sys.argv[1], "r")
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
