import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, m = map(int, input().split())

    if n < m:
        print(1)
        print(n)
        return
    elif n == m:
        print(2)
        print(-1, n + 1)
        return

    if n % m != 0:
        print(1)
        print(n)
    else:
        print(2)
        print(-1, n + 1)


if __name__ == "__main__":
    for i in range(int(input())):
        solve()
