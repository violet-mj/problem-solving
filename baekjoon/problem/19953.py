import sys
from collections import deque
input = lambda: sys.stdin.readline().rstrip()
dx = (-1, 0, 1, 0)
dy = (0, 1, 0, -1)

def solve():
	h, w, o, f, xs, ys, xe, ye = map(int, input().split())
	graph = [[0 for i in range(w+1)] for i in range(h+1)]
	visited = [[False for i in range(w+1)] for i in range(h+1)]
	
	for i in range(o):
		x, y, l = map(int, input().split())
		graph[x][y] = l
	
	q = deque()
	q.append((xs, ys, f))
	visited[xs][ys] = True

	while q:
		currX, currY, currF = q.popleft()
	
		if currX == xe and currY == ye:
			return "잘했어!!"
		
		if currF == 0: break
		
		for i in range(4):
			nx = currX + dx[i]
			ny = currY + dy[i]
			
			if nx < 1 or nx > h or ny < 1 or ny > w or visited[nx][ny]: continue

			if graph[nx][ny] - graph[currX][currY] < 0:
				visited[nx][ny] |= 1
				q.append((nx, ny, currF - 1))
			else:
				if currF >= graph[nx][ny] - graph[currX][currY]:
					visited[nx][ny] |= 1
					q.append((nx, ny, currF - 1))
		 

	
	return "인성 문제있어??"

if __name__ == "__main__":
	t = int(input())
	for i in range(t):
		print(solve())
