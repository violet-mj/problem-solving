import sys
from bisect import *
input = lambda: sys.stdin.readline().rstrip()

def init():
    global prefixDp
    dp = [[0 for j in range(10)] for i in range(13)]
    prefixDp = [[0 for j in range(10)] for i in range(13)]
    for i in range(10): 
        dp[1][i] = 1


    blue = [0, 9]

    for i in range(2, 13):
        for j in range(10):
            for z in range(10):
                if j == z: continue
                dp[i][j] += dp[i - 1][z]
        blue.append(blue[-1] + sum(dp[i]))
    
    for i in range(1, 13):
        for j in range(10):
            if j > 0:
                prefixDp[i][j] = prefixDp[i][j-1] + dp[i][j]
            else:
                prefixDp[i][j] = prefixDp[i-1][-1]

    res = 0

    
    print(*dp, sep="\n")
    print(*prefixDp, sep="\n")

def solve():
    global prefixDp
    x = int(input())
    
    res = 0

    for i in range(12, 0, -1):
        a = bisect_left(prefixDp[i], x)
        print("a", a)
        res += a * (10 ** (i - 1))
        if a != 0: x -= prefixDp[i][a - 1]
    print(res)

if __name__ == "__main__":
    init()
    for i in range(int(input())):
        solve()
