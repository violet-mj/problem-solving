
import sys
from collections import defaultdict
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

MOD = int(1e9 + 7)

def mul(x, y):
    if y == 0:
        return 1
    
    divide = mul(x, y // 2)

    if y % 2 == 0:
        return divide * divide % MOD
    else:
        return x * divide * divide % MOD

def tracking(i, j, contribute, count):
    global m, n, k, result, d, dp

    if count == n:
        if contribute >= m:
            return 1
        else:
            return 0

    if count < n and contribute >= m:
        diff = n - count
        return mul(6, diff)

    if count > 25 and contribute < m:
        return 0

    if dp[i][count][contribute] != -1:
        return dp[i][count][contribute]



    res = 0
    for ii in range(3):
        for jj in range(2):
            
            if ii == i:
                res += tracking(ii, jj, contribute + (k[jj][ii] // 2), count + 1)
            else:
                res += tracking(ii, jj, contribute + k[jj][ii], count + 1)
    
    dp[i][count][contribute] = res % MOD

    return dp[i][count][contribute]
    



def solve():
    global m, n, k, d, dp, result
    result=0
    n, m = map(int, input().split())
    dp = [[[-1 for i in range(26)] for i in range(26)] for i in range(3)]
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    d = defaultdict(int)

    k = [A, B]

    for i in range(3):
        for j in range(2):
            result += tracking(i, j, k[j][i], 1) % MOD

    result %= MOD

if __name__ == "__main__":
    solve()
    print(result)
