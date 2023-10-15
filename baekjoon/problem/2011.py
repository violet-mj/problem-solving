import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def solve():
    enc = input()
    es = len(enc)

    dp = [0 for i in range(es + 1)]
    dp[0] = 1
    dp[1] = 0 if int(enc[0]) == 0 else 1

    for i in range(2, es + 1):
        dp[i] += dp[i-1] if int(enc[i-1]) != 0 else 0
        dp[i] %= 1000000
        dp[i] += dp[i-2] if 10 <= int(enc[i-2:i]) <= 26 else 0
        dp[i] %= 1000000

    return dp[-1]
if __name__ == "__main__":
    print(solve())
