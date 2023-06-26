import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    L = [input().split() for i in range(n)]

    L.sort(key=lambda x: x[0])
    L.sort(key=lambda x: int(x[3]), reverse=True)
    L.sort(key=lambda x: int(x[2]))
    L.sort(key=lambda x: int(x[1]), reverse=True)

    for i in L:
        print(i[0])

if __name__ == "__main__":
    solve()
