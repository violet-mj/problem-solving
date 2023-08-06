import sys
from collections import deque
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def bfs(currNode):
    global n, m, graph
    q = deque()
    q.append(currNode)
    visited = [False for i in range(n + 1)]
    visited[currNode] = True
    s = 1

    while q:
        cNode = q.popleft()
        for nextNode in graph[cNode]:
            if not visited[nextNode]:
                s += 1
                visited[nextNode] = True
                q.append(nextNode)
    
    return True if s == n else False

def solve():
    global n, m, graph
    n, m = mii()

    graph = [[] for i in range(n + 1)]

    for i in range(m):
        s, e = mii()
        graph[s].append(e)

    for i in range(1, n + 1):
        if bfs(i):
            return i

    return -1

if __name__ == "__main__":
    print(solve())
