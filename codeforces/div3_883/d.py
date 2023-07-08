import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, d, h = map(int, input().split())
    L = list(map(int, input().split()))

    init = d * h * (1/2)

    result = 0

    for i in range(n-1):
        if L[i] + h <= L[i+1]:
            result += init
        else:
            ratio = (h - (L[i+1] - L[i])) / h
            ratiow = ratio ** 2
            result += init - (init * ratiow)

    result += init

    return result



if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())

