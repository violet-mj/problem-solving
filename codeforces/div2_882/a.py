
import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, k = map(int, input().split())
    L = list(map(int,input().split()))

    check = []
    for i in range(n - 1):
        check.append(abs(L[i] - L[i + 1]))
    check.sort()

    result = 0

    for i in range(len(check) - k + 1):
        result += check[i]

    return result

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
