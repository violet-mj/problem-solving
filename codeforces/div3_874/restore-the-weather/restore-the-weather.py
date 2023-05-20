import sys
from collections import deque, defaultdict
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    aSort = sorted(a)
    bSort = sorted(b)
    d = defaultdict(deque)
    for i in range(n):
        d[aSort[i]].append(bSort[i])


    result = []
    for i in a:
        result.append(d[i].popleft())

    return result

if __name__ == "__main__":
    for i in range(int(input())):
        print( *solve())
