
import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    resultS = '*'
    c = 0
    r = []
    L = []
    for i in range(n):
        resultS = '*'
        c = 0
        a = input().split()

        if a[0] == "enqueue":
            b = a[1]
            L.append(b)
        else:
            if len(L) == 0:
                r.append('*')
                continue
            for j in L:
                sCount = L.count(j)
                if sCount > c:
                    resultS = j
                    c = sCount
            r.append(resultS)
            L.remove(resultS)

    print(*r)

            

if __name__ == "__main__":
    solve()
