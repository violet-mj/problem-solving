import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def solve():
    h, w = map(int, input().split())
    graph = [list(input()) for i in range(h)]

    for i in range(h):
        for j in range(w):
            squared = 0
            if graph[i][j] == '#':
                continue
            for z in range(4):
                nx = i + dx[z]
                ny = j + dy[z]

                if nx < 0 or nx >= h or ny < 0 or ny >= w:
                    continue

                if graph[nx][ny] == '#':
                    squared += 1

            if squared >= 2:
                return (i + 1, j + 1)
if __name__ == "__main__":
    print(*solve())
