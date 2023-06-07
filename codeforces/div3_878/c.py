import sys
from math import log2
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, k, q = map(int, input().split())
    a = [*map(int, input().split())]
    result = 0
    check = 0

    for i in range(len(a)):
        if a[i] <= q:
            check += 1
        else:
            if check >= k:
                result += ((check - k + 1) * (check - k + 2) // 2)
            check = 0

    if check != 0:
        if check >= k:
            result += ((check - k + 1) * (check - k + 2) // 2)

    return result


if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
