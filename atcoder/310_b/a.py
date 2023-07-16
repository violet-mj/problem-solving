import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write
MIN = sys.maxsize

def solve():
    n, p, q = map(int, input().split())
    L = list(map(int, input().split()))

    return min(p, min(L) + q)

if __name__ == "__main__":
    print(solve())
