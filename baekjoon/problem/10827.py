
import sys
from decimal import Decimal, Context
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())


def solve():
    n, m = input().split()

    n = Decimal(n)

    return Context(prec=20000).power(n, int(m))
if __name__ == "__main__":
    print(solve())
