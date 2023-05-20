
import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

SNUKE = 'snuke'

dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]

def check(x, y):
    global graph, h, w

    for i in range(8):
        c = []
        flag = True
        for j in range(5):
            nx = x + dx[i] * j 
            ny = y + dy[i] * j
            if nx < 0 or nx >= h or ny < 0 or ny >= w:
                flag = False
                break
            if graph[nx][ny] == SNUKE[j]:
                c.append((nx, ny))
            else:
                flag = False
                break

        if flag:
            for i in c:
                print(i[0] + 1, i[1] + 1)
            sys.exit(0)





def solve():
    global graph, h, w
    h, w = map(int, input().split())

    graph = [list(input()) for i in range(h)]

    for i in range(h):
        for j in range(w):
            if graph[i][j] == SNUKE[0]:
                check(i, j)



if __name__ == "__main__":
    solve()
