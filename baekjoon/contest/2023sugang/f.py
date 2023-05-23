import sys
from collections import deque
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, k = map(int, input().split())

    d = deque([i for i in range(1,n+1)])

    while len(d) >= k:
        first = d.popleft()
        d.append(first)

        for i in range(k-1):
            d.popleft()

    return d.popleft()


if __name__ == "__main__":
    print(solve())
