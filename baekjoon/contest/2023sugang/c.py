
import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write
dx = (-1, 0, 1, 0)
dy = (0, 1, 0, -1)

def solve():
    n = int(input())
    x, y = map(int, input().split())

    result = 0
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 1 or nx > n or ny < 1 or ny > n:
            continue
        result += 1

    return result


if __name__ == "__main__":
    print(solve())
