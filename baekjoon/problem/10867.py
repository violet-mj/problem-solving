import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def solve():
    n = ii()
    L = list(mii())
    L = list(set(L))
    L.sort()
    print(*L)

if __name__ == "__main__":
    solve()
