import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())


def solve():
    n = 10000
    l = [0 for i in range(n + 1)]
    l[1] = 1
    for i in range(2, n + 1):
        l[i] = l[i - 1] + l[i - 2]

    print("[", end="")
    print(*l, sep=", ")
    print("]",end="")
    print("[int(input())]")

if __name__ == "__main__":
    solve()
