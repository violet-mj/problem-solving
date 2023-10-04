import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def solve():
    a, b = mii()
    ai = set(list(mii()))
    bi = set(list(mii()))

    res = sorted(list(ai - bi))

    print(len(res))
    print(*res)

if __name__ == "__main__":
    solve()
