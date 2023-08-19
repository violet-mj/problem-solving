import sys
from collections import defaultdict
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def solve():

    n = int(input())

    d = defaultdict(list)

    max_ =  -1

    for i in range(n):
        f, deli = mii()
        d[f].append(deli)

    for i in d:
        d[i].sort(reverse=True)
        if len(d[i]) >= 2:
            max_ = max(max_, d[i][0] + d[i][1] // 2)

    cache = []
    for i in d:
        cache.append(d[i][0])
    cache.sort(reverse=True)

    if len(cache) >= 2:
        max_ = max(cache[0] + cache[1], max_)

    return max_
if __name__ == "__main__":
    print(solve())
