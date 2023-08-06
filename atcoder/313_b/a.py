import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def solve():

    n = ii()
    L = list(mii())

    if max(L) == L[0] and L.count(L[0]) == 1:
        return 0

    return max(L) - L[0] + 1


if __name__ == "__main__":
    print(solve())
