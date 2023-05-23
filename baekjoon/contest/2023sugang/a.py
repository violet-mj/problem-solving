import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    L = list(map(int, input().split()))

    max_ = 0

    for idx, i in enumerate(L):
        max_ = max(max_, i - n + idx)

    return max_


if __name__ == "__main__":
    print(solve())
