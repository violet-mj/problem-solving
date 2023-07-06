import sys
input = lambda: sys.stdin.readline().rstrip()
print = sys.stdout.write
INF = sys.maxsize

def dfs(currNode, count):
    global n, L, dp

    if currNode >= n:
        return

    if count >= dp[currNode]:
        return

    dp[currNode] = count

    for i in range(1, L[currNode] + 1):
        dfs(currNode + i, count + 1)

def solve():
    global n, L, dp
    n = int(input())
    L = list(map(int,input().split()))
    
    dp = [INF] * n

    dfs(0,  0)

    print(f'{dp[n-1] if dp[n-1] != INF else -1}\n')

if __name__ == "__main__":
    solve()
