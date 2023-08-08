import sys
from collections import defaultdict
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def solve():
    n = ii()
    L = list(mii())
    d = defaultdict(int)

    for i in L:
        d[i] += 1

    q = ii()

    result = []

    for i in range(q):
        x, y = mii()

        if x**2 - 4*y < 0:
            result.append(0)
            continue

        sqrtp = (x**2-4*y) ** 0.5

        if sqrtp != int(sqrtp):
            result.append(0)
            continue

        cp1 = (x + (x**2-4*y) ** 0.5)
        cp2 = (x - (x**2-4*y) ** 0.5)

        count = 0



        if cp1 % 2 == 0:
            cp1 //= 2

            if cp1 != x - cp1:
                count += (d[cp1] * d[x - cp1])
            else:
                count += (d[cp1] * (d[cp1] - 1) // 2)

        if cp2 % 2 == 0:
            cp2 //= 2
            if cp2 != x - cp2:
                count += (d[cp2] * d[x - cp2])
            else:
                count += (d[cp2] * (d[cp2] - 1) // 2)

        result.append(count // 2)

    print(*result)

if __name__ == "__main__":
    t = ii()
    for i in range(t):
        solve()
