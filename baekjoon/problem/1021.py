import sys
from collections import deque
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def solve():
    n, m = mii()
    dq = deque([i for i in range(1, n + 1)])

    L = list(mii())

    res = 0
    for i in L:
        idx = dq.index(i) 
        if idx < n - idx:
            dq.rotate(-idx)
        else:
            dq.rotate(n - idx)
        res += min(idx, n - idx)
        dq.popleft()
        n -= 1

    return res

if __name__ == "__main__":
    print(solve())
