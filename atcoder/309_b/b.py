import sys
from collections import deque
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

direction = [(0,1), (1,0), (0, -1), (-1, 0)]

def solve():
    n = int(input())
    graph = [ list(map(int, list(input()))) for i in range(n)]

    d = 0
    x = 0
    y = 0

    L = deque()

    while 1:
        L.append(graph[x][y])

        nx = x + direction[d][0]
        ny = y + direction[d][1]

        if nx < 0 or nx >= n or ny < 0 or ny >= n:
            d += 1
            if d == 4:
                break
            nx = x + direction[d][0]
            ny = y + direction[d][1]

        x = nx
        y = ny

    L.pop()
    a = L.pop()
    L.appendleft(a)

    L = list(L)
    d = 0
    x = 0
    y = 0
    count = 0

    while 1:
        graph[x][y] = L[count] 

        if d == 4:
            break
        nx = x + direction[d][0]
        ny = y + direction[d][1]


        if nx < 0 or nx >= n or ny < 0 or ny >= n:
            d += 1
            nx = x + direction[d][0]
            ny = y + direction[d][1]

        
        if nx == 0 and ny == 0:
            break

        x = nx
        y = ny
        count += 1

    for i in range(n):
        print(*graph[i], sep="")

if __name__ == "__main__":
    solve()
