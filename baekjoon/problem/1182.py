
import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def backtracking(index, count):
    global n, S, L, result

    if count == S:
        result += 1

    for i in range(index + 1, n):
        backtracking(i, count + L[i])

def solve():
    global n, S, L, result
    n, S = map(int, input().split())
    L = list(map(int, input().split()))
    result = 0

    for i in range(n):
        backtracking(i, L[i])

    return result


if __name__ == "__main__":
    print(solve())
