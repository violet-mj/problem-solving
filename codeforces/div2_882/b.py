
import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write
binMax = 2**30-1


def solve():
    n = int(input())
    L = list(map(int, input().split()))
    first = binMax

    for i in range(n):
        first &= L[i]

    if first != 0:
        return 1
    else:
        f = binMax
        result = 0
        for i in range(n):
            f &= L[i]
            if f == 0:
                result += 1
                f = binMax 

        return result


if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
