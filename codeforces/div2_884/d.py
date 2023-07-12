import sys
import string
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write
alpha = string.ascii_lowercase

def solve():
    n = int(input())

    sqrtn = int(n ** 0.5)
    check = []
    
    if n <= 2:
        return alpha[:n]

    for i in range(1, sqrtn + 1):
        if n % i == 0:
            check.append(i)
            if i != n // i:
                check.append(n // i)

    check.sort()
    tmp = 1
    c = -1
    for i in check:
        if tmp == i:
            tmp += 1
            continue
        else:
            c = tmp

    return alpha[:c] * (n // c) + alpha[:c][:n%c]

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
