import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    L = list(map(int, input().split()))
    L.sort()

    result = sum(L)

    if result % 2 == 0:
        return result
    else:
        for i in range(len(L)):
            if L[i] % 2 == 1:
                return result - L[i]


if __name__ == "__main__":
    print(solve())
