import sys
from functools import cmp_to_key

input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def compare(i1, i2):
    if i1[1] * i2[2] < i2[1] * i1[2]:
        return 1
    elif i1[1] * i2[2] > i2[1] * i1[2]:
        return -1
    else:
        if i1[0] < i2[0]:
            return -1
        else:
            return 1

def solve():
    n = int(input())

    L = []

    for i in range(n):
        a, b = map(int, input().split())
        c = a + b
        L.append((i+1, a, c))

    L.sort(key=cmp_to_key(compare))
    result = []
    for i in L:
        result.append(i[0])

    print(*result)

if __name__ == "__main__":
    solve()
