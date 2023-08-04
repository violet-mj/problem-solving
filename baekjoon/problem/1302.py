import sys
from collections import defaultdict
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def solve():
    n = ii()
    L = [input() for i in range(n)]
    d = defaultdict(int)

    for i in L:
        d[i] += 1

    a = list(d.items())

    a.sort(key=lambda x: (-x[1], x[0]))

    return a[0][0]

if __name__ == "__main__":
    print(solve())
