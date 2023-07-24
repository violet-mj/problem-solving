import sys
from math import ceil
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    L = list(map(int, input().split()))
    min_ = sys.maxsize

    for i in range(1, n):
        if L[i] - L[i-1] < 0:
            return 0
        else:
            min_ = min(min_, L[i] - L[i-1])

    return ceil((min_ + 1) / 2)

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
