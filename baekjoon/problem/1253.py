import sys
from collections import defaultdict
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def binarySearch(l, r, v):
    while l + 1 < r:
        mid = (l + r) // 2
        if L[mid] == v:
            return True

        if L[mid] < v:
            l = mid
        else:
            r = mid

    return False




def solve():
    global n, L
    n = int(input())
    L = list(map(int, input().split()))
    Set = set()
    d = defaultdict(int)
    db = defaultdict(lambda: False)

    for i in L:
        d[i] += 1

    for i in range(n):
        for j in range(i+1, n):
            if L[i] == 0 and L[j] == 0:
                if d[0] >= 3:
                    db[L[i] + L[j]] = True
            elif L[i] == 0:
                if d[L[j]] >= 2:
                    db[L[i] + L[j]] = True
            elif L[j] == 0:
                if d[L[i]] >= 2:
                    db[L[i] + L[j]] = True
            else:
                db[L[i] + L[j]] = True
    result = 0
    for i in L:
        if db[i]:
            result += 1

    return result



if __name__ == "__main__":
    print(solve())
