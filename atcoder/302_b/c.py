
import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def diff(f, s):
    global n, m, L, visitedSet
    count = 0

    for i in range(m):
        if f[i] != s[i]:
            count += 1

    return count

def check(v):
    global n, m, L, visitedSet, result

    if len(visitedSet) == n:
        print("Yes")
        sys.exit(0)

    for i in range(n):
        if i not in visitedSet:
            if diff(v, L[i]) == 1:
                visitedSet.add(i)
                check(L[i])
                visitedSet.remove(i)

def solve():
    global n, m, L, visitedSet, result
    n, m = map(int, input().split())

    L = [input() for i in range(n)]

    visitedSet = set()
    result = []

    for i in range(n):
        visitedSet.add(i)
        check(L[i])
        visitedSet.remove(i)

    print("No")

if __name__ == "__main__":
    solve()
