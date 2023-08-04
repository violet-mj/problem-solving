import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def findRoot(x):
    global parent
    if parent[x] != x:
        parent[x] = findRoot(parent[x])

    return parent[x]

def unionRoad(x, y):
    global parent
    x = findRoot(x)
    y = findRoot(y)

    if x < y:
        parent[y] = x
    else:
        parent[x] = y

def solve(tn):
    global parent
    n =  int(input())
    xi = list(mii())
    yi = list(mii())
    r = list(range(n))

    parent = [i for i in range(n)]

    coords = [*zip(xi, yi, r)]

    e = float(input()) 

    candidates = []

    for i in range(n):
        for j in range(i+1, n):
            cx1, cy1, idx1 = coords[i]
            cx2, cy2, idx2 = coords[j]

            dist = (cx1 - cx2) ** 2 + (cy1 - cy2) ** 2
            value = dist * e

            candidates.append((idx1, idx2, value))

    candidates.sort(key= lambda x: x[2])

    res = 0
    for i1, i2, value in candidates:

        if findRoot(i1) != findRoot(i2):
            res += value
            unionRoad(i1, i2)

    return f'#{tn} {round(res)}'

if __name__ == "__main__":
    t = ii()
    for i in range(t):
        print(solve(i+1))
