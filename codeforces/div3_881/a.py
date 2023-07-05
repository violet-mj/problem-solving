import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    L = list(map(int, input().split()))
    Ls = len(L)
    L.sort()
    result = 0
    for i in range(Ls // 2):
        result += L[-1-i] - L[i]

    return result


if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
