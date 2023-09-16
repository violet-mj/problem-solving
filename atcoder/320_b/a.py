import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())


def solve():
    a, b = mii()
    return a ** b + b ** a

if __name__ == "__main__":
    print(solve())
