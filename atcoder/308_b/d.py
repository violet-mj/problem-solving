import sys
from collections import deque
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

SNUKE = ['s', 'n', 'u', 'k', 'e']


def solve():
    n, m = map(int, input().split())
    graph = [list(input()) for i in range(n)]
    visited = [[[False for i in range(m)] for j in range(n)] for i in range(4)]

    if graph[0][0] != 's':
        return "No"

    q = deque()

    for i in range(4):
        visited[i][0][0] = True
    q.append((0, 0, 0))

    while q:
        cx, cy, di = q.popleft()

        if cx == n - 1 and cy == m - 1:
            return "Yes"

        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue

            if visited[i][nx][ny]:
                continue
            
            if graph[nx][ny] != SNUKE[(di + 1) % 5]:
                continue

            visited[i][nx][ny] = True
            q.append((nx, ny, di + 1))

    return "No"

if __name__ == "__main__":
    print(solve())
