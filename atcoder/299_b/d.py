import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write
flush = sys.stdout.flush


def solve():
    n = int(input())
    L = []

    l = 1
    r = n

    while l + 1 < r:
        mid = (l + r) // 2

        print(f"? {mid}")
        flush()
        s = int(input())

        if s == 0:
            l = mid
        else:
            r = mid

    print(f"! {l}")

if __name__ == "__main__":
    solve()

