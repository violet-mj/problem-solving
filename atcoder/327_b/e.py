import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def point9(n):
    return 1 * (1- 0.9 ** n ) / (1-0.9)


INF = 10000000000000.0
def solve():
    n = ii()
    p = [0]+list(mii())
    point9 = [0]
    cnt = 1
    for i in range(5002):
        point9.append(point9[-1] + cnt)
        cnt *= 0.9
    dp = [[-INF for i in range(n+1)] for i in range(n+1)]
    dp[0][0] = 0.0
    for i in range(1, n + 1):
        for j in range(1, i+1):
            if j == 1: dp[i][j] = max(dp[i-1][1], p[i])
            elif i == j: dp[i][j] = dp[i-1][j-1] * 0.9 + p[i]
            else: dp[i][j] = max(dp[i-1][j-1] * 0.9 + p[i], dp[i-1][j])

    max_ = -INF
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            max_ = max(max_, dp[i][j] / point9[j] - (1200 / (j ** 0.5)))

    return max_

if __name__ == "__main__":
    print(solve())
