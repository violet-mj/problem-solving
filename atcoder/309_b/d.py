import sys
from collections import deque
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n1, n2, M = map(int, input().split())

    graph = [[] for i in range(n1 + n2 + 1)]
    visited = [False] * (n1 + n2 + 1)

    for i in range(M):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    
    q1 = deque()
    max1 = 0
    q1.append((1, 0))
    visited[1] = True

    while q1:
        currNode, currDist = q1.popleft()

        for i in graph[currNode]:
            if visited[i]:
                continue
            
            visited[i] = True
            max1 = max(max1, currDist + 1)
            q1.append((i, currDist + 1))

    q2 = deque()
    max2 = 0
    q2.append((n1+n2, 0))
    visited[n1+n2] = True

    while q2:
        currNode, currDist = q2.popleft()

        for i in graph[currNode]:
            if visited[i]:
                continue
            
            visited[i] = True
            max2 = max(max2, currDist + 1)
            q2.append((i, currDist + 1))


    return max1 + max2 + 1

if __name__ == "__main__":
    print(solve())
