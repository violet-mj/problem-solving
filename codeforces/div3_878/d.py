import sys
from math import log2
from bisect import bisect_right, bisect_left
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def promising(init, mid, a):
    global n
    check = init + 2 * mid
    nexts = bisect_right(a, check) - 1
    if nexts == n - 1:
        return True
    nexts += 1
    check = a[nexts] + 2 * mid
    nexts = bisect_right(a, check) - 1
    if nexts == n - 1:
        return True
    nexts += 1
    check = a[nexts] + 2 * mid
    nexts = bisect_right(a, check)
    if nexts == n:
        return True

    return False


def solve():
    global n
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()

    l = -1
    r = max(a) - 1
    init = a[0]

    while l + 1 < r:
        mid = (l + r) // 2

        if promising(init, mid, a):
            r = mid
        else:
            l = mid

    return r

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
