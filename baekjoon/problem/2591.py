import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def backtracking(curr, currNum):
    global n, s, dp
    if currNum[0] == '0' or int(currNum) > 34:
        return 0

    if ~dp[curr]:
        return dp[curr]

    count = 0

    if curr + 1 < n:
        count += backtracking(curr + 1, s[curr+1:curr+2])

    if curr + 2 < n:
        count += backtracking(curr + 2, s[curr+1:curr+3])

    dp[curr] = count

    return dp[curr]

def solve():
    global n, s, dp
    s = input()
    n = len(s)
    dp = [-1] * n
    dp[-1] = 1
    result = 0
    result += backtracking(0, s[0]) 
    if n != 1:
        result += backtracking(1, s[:2])

    return result

if __name__ == "__main__":
    print(solve())
