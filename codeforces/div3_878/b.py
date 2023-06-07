import sys
from math import log2
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, k = map(int, input().split())
    if log2(n) < k:
        return n + 1
    else:
        return 2 ** k

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
