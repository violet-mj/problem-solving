import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    L = [0] * n

    k = 1 if n % 2 == 0 else 0

    cnt = 1

    for i in range(k, n, 2):
        L[i] = cnt
        cnt += 1


    for i in range(n-2, -1, -2):
        L[i] = cnt
        cnt += 1

    return L

if __name__ == "__main__":
    print(*solve())
