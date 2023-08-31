import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())


def solve():
    n, m = mii()
    a = ii()
    b = ii()
    return a * b

if __name__ == "__main__":
    print(solve())
