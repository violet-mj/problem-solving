import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n, k = map(int, input().split())
    L = list(map(int, input().split()))
    L.sort()

    max_ = 

    for i in range(n-1):


    m = (1 << k) - 1
    x = L[0] ^ m
    y = L[1] ^ m

    xx = x & y

    return (1, 2, xx)

if __name__ == "__main__":
    for i in range(int(input())):
        print(*solve())
