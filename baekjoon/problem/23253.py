import sys
from collections import defaultdict
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n, m = map(int, input().split())
    stacks = []

    for i in range(m):
        ki = int(input())
        a = list(map(int, input().split()))

        if sorted(a, reverse=True) != a:
            return "No"

    return "Yes"


if __name__ == "__main__":
    print(solve())
