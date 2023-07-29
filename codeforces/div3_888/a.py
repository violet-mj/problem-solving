import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n, m, k, H = map(int, input().split())

    maxDiff = (m-1) * k

    L = list(map(int, input().split()))
    res = 0

    for i in L:
        if 0 < abs(H - i) <= maxDiff:
            if abs(H - i) % k == 0:
                res += 1
    return res

    

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
