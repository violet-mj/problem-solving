import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write
MAX = sys.maxsize


def dfs(typed, isCapslock, cost):
    global x, y, z, s, sSize, dp

    if typed >= sSize - 1:
        return 

    if (s[typed + 1] == 'a' and isCapslock == 0) or (s[typed + 1] == 'A' and isCapslock == 1):
        if dp[typed+1][isCapslock] <= cost + x:
            return dp[typed+1][isCapslock]
        else:
            dp[typed + 1][isCapslock] = cost + x
            dfs(typed + 1, isCapslock, cost + x)

    if (s[typed + 1] == 'a' and isCapslock == 1) or (s[typed + 1] == 'A' and isCapslock == 0):
        if dp[typed+1][isCapslock] <= cost + y:
            return dp[typed+1][isCapslock]
        else:
            dp[typed + 1][isCapslock] = cost + y
            dfs(typed + 1, isCapslock, cost + y)


    if dp[typed][1^isCapslock] <= cost + z:
        return dp[typed][1^isCapslock]
    else:
        dp[typed][1^isCapslock] = cost + z
        dfs(typed, 1^isCapslock, cost + z)
    
def solve():
    global x, y, z, s, sSize, dp
    x, y, z = map(int, input().split())
    s = input()
    sSize = len(s)

    dp = [[MAX for i in range(2)] for i in range(sSize)]

    if s[0] == 'a':
        dp[1][0] = x
        dfs(1, 0, x)

    if s[0] == 'A':
        dp[1][0] = y
        dfs(1, 0, y)

    dfs(0, 1, z)
    dp[0][1] = z

    print(*dp, sep="\n")

if __name__ == "__main__":
    solve()
