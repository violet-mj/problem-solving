
import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    L = list(map(int, input().split()))


    for i in range(n-1, 0, -1):
        if L[i] < L[i-1]:
            return max(L[:i+1])

    return 0


if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
