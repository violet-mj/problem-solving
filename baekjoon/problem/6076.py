import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def solve():
    c, h = mii()
    L = [ii() for i in range(h)]
    dp = [0 for i in range(c + 1)]
    dp[0] = 1

    for i in L:
        for j in range(c, -1, -1):
            if j - i < 0: continue
            if dp[j - i]: dp[j] = 1
    
    print(dp[:9])

    for i in range(c, -1, -1):
        if dp[i]:
            return i

if __name__ == "__main__":
    print(solve())
