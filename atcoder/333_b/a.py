import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())


def solve():
    n = input()
    return n * int(n)

if __name__ == "__main__":
    print(solve())
