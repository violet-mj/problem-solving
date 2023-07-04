import sys
from math import ceil
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())

    l = -1
    r = 2 ** 32

    while l + 1 < r:
        mid = (l + r) // 2

        if mid ** 2 >= n:
            r = mid
        else:
            l = mid

    return r

if __name__ == "__main__":
    print(solve())
