import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write
sys.setrecursionlimit(10**5)

def debug(*args):
    print(*args)
    return

def dfs(currNode, isBlack):
    global coloring, graph, black, white
    if coloring[currNode] != -1:
        if coloring[currNode] != isBlack:
            print(0)
            sys.exit(0)
        return 
    else:
        coloring[currNode] = isBlack
        if isBlack:
            black += 1
        else:
            white += 1

    for i in graph[currNode]:
        dfs(i, 1 ^ isBlack)




def solve():
    global coloring, graph, black, white
    v, e = map(int, input().split())
    visited = [False] * (v + 1)
    graph = [[] for i in range(v + 1)]
    coloring = [-1] * (v + 1) 
    black = 0
    white = 0
    for i in range(e):
        ui, vi = map(int, input().split())
        graph[ui].append(vi)
        graph[vi].append(ui)
        
    dfs(1, 1)
    count = 0
    for i in range(1, v+1):
        if coloring[i] == -1:
            count += 1
    if count == 1:
        return black + white
    elif count > 1:
        return 0
    else:
        return black * white - e

if __name__ == "__main__":
    print(solve())
