import sys
from collections import deque
input = lambda: sys.stdin.readline().rstrip()

dx = [-1, 0, 1, 0, -1, -1, 1, 1]
dy = [0, 1, 0, -1, -1, 1, -1, 1]

def bfs(cx, cy):
    global n, graph, check, visited
    q = deque()
    q.append((cx, cy))
    visited[cx][cy] = True

    while q:
        currX, currY = q.popleft()

        for i in range(8):
            nextX = currX + dx[i]
            nextY = currY + dy[i]

            if nextX < 0 or nextX >= n or nextY < 0 or nextY >= n: continue
            if visited[nextX][nextY]: continue
            if graph[nextX][nextY] == '*': continue

            visited[nextX][nextY] = True

            if check[nextX][nextY] == 0:
                q.append((nextX, nextY))

def solve(tn):
    global n, graph, check, visited
    n = int(input())
    graph = [list(input()) for i in range(n)]

    check = [[0 for i in range(n)] for i in range(n)]
    visited = [[False for i in range(n)]for i in range(n)]


    for i in range(n):
        for j in range(n):
            if graph[i][j] == '.':
                count = 0
                for d in range(8):
                    nx = i + dx[d]
                    ny = j + dy[d]
                    if nx < 0 or nx >= n or ny < 0 or ny >= n: continue
                    count += 1 if graph[nx][ny] == '*' else 0
                check[i][j] = count
            else:
                check[i][j] = -1

    res = 0
    for i in range(n):
        for j in range(n):
            if(check[i][j] == 0 and not visited[i][j]):
                bfs(i, j)
                res += 1

    for i in range(n):
        for j in range(n):
            if not visited[i][j] and check[i][j] > 0:
                res += 1

    return f'#{tn} {res}'

if __name__ == "__main__":
    for i in range(t:=int(input())):
        print(solve(i+1))
