import sys
from math import ceil
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    result = n ** 0.5
    result = ceil(result)

    print(result)


if __name__ == "__main__":
    solve()
