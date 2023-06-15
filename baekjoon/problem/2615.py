import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write


def check(x, y, curr):
    global graph
    dx = [-1, 0, 1, 1]
    dy = [1, 1, 1, 0]

    for dirX in dx:
        for dirY in dy:
            count = 0
            if 0 <= x - dirX < 19 and 0 <= y - 1 < 19:
                if graph[x - dirX][y - dirY] == curr:
                    continue
            for i in range(19):
                nx = x + i * dirX
                ny = y + i * dirY   
                if nx < 0 or nx >= 19 or ny < 0 or ny >= 19:
                    break   
                if graph[nx][ny] != curr:
                    break
                
                count += 1
            if count == 5:
                return True

    return False

def solve():
    global graph
    graph = []

    for i in range(19):
        graph.append(list(map(int, input().split())))

    for i in range(19):
        for j in range(19):
            if check(i, j, graph[i][j]) and graph[i][j] in (1,2):
                print(graph[i][j])
                print(i+1, j+1)
                return
    print(0)


if __name__ == "__main__":
    solve()
