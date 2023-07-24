import sys
from collections import deque
input = lambda: sys.stdin.readline().rstrip()
print = sys.stdout.write

def solve():
    n = int(input())
    node = ['&' for i in range(n + 1)]
    visited = [False for i in range(n + 1)]

    for i in range(n):
        curr, sign, *nexts = input().split()
        node[int(curr)] = sign

    q = deque()
    q.append(1)
    visited[1] = True

    while q:
        currNode = q.popleft()

        currNodeMul2 = currNode * 2

        if(currNodeMul2 + 1 > n):
            if(not node[currNode].isdigit()):
                return 0
        else:
            if(node[currNode].isdigit()):
                return 0

        for i in range(1, 3):
            if(currNodeMul2 + i > n) continue
            if(visited[currNodeMul2 + i]): continue
            visited[currNodeMul2 + i] = True
            q.append(currNodeMul2 + i)

    return 1

if __name__ == "__main__":
    for i in range(1, 11):
        print(f'#{i} {solve()}')
