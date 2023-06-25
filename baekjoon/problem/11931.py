import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    L = [int(input()) for i in range(n)]

    L.sort(reverse=True)

    print(*L, sep="\n")

if __name__ == "__main__":
    solve()
