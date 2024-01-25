import sys


def main():
    file = open(sys.argv[1], "r")
    for line in file:
        number = int(line.strip('\n'))
        a = 2
        print("{:d}".format(number))
        while True:
            if number % a == 0:
                break
            a += 1
        b = round(number / a)
        
        print(f"{number}={b}*{a}")
    file.close()
main()
