
def solve():
    a, b = input().split()
    al = len(a)
    bl = len(b)

    dp = [[0 for i in range(bl+ 1)] for i in range(al+1)]

    for i in range(1, al + 1):
        for j in range(1, bl + 1):
            if(a[i-1] == b[j-1]):
                dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j-1])
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return dp[al][bl]

if __name__ == "__main__":
    for i in range(int(input())):
        print(f'#{i+1} {solve()}')
