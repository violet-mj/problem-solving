import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def promising(num):
    global A, B

    aC = 0
    bC = 0

    for i in A:
        if num >= i:
            aC += 1

    for i in B:
        if num <= i:
            bC += 1

    
    return aC >= bC


def solve():
    global A, B
    n, m = mii()

    A = list(mii())
    B = list(mii())

    l = 0
    r = 10 ** 9 + 1

    while l + 1 < r:
        mid = (l + r) >> 1

        if promising(mid):
            r = mid
        else:
            l = mid

    return r


if __name__ == "__main__":
    print(solve())
