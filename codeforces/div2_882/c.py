import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def dfs(px):
    global n, L, dp

    if dp[px[-1]]:
        return
    
    dp[px[-1]] = True
    
    for i in range(n-1, 0, -1):
        tmp = px[-1]^px[i-1]
        dfs(px + [tmp])

def solve():
    global n, L, dp
    n = int(input())
    L = list(map(int, input().split()))

    dp = [False] * (2 ** 8 + 1)

    prefixXor = [L[0]]
    dp[prefixXor[-1]] = True

    for i in range(1, n):
        prefixXor.append(prefixXor[-1]^L[i])
        dp[prefixXor[-1]] = True

    dfs(prefixXor)

    for i in range(2**8, -1, -1):
        if dp[i]:
            return i

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
