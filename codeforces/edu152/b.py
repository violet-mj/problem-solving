import sys
from math import ceil
from heapq import heappop, heappush
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n, k = map(int, input().split())
    L = list(map(int, input().split()))

    result = []

    div0 = []
    kk = []

    for idx, i in enumerate(L):
        if i % k == 0:
            div0.append(idx + 1)
        else:
            kk.append((i % k, idx + 1)) 

    div0.sort()
    kk.sort(key=lambda x: (-x[0], x[1]))




    kkk = []

    for i, j in kk:
        kkk.append(j)

    return div0 + kkk



if __name__ == "__main__":
    for i in range(int(input())):
        print(*solve())
