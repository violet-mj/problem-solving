import sys
sys.setrecursionlimit(10**9)
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def dfs(node, prevNode):
    global n, graph, leafs

    if leafs[node] != -1:
        return leafs[node]

    if len(graph[node]) == 1 and node != 1:
        leafs[node] = 1
        return 1
    
    l = 0

    for i in graph[node]:
        if i != prevNode:
            l += dfs(i, node)

    leafs[node] = l
    return leafs[node]
    
def solve():
    global n, graph, leafs
    n = int(input())
    graph = [[] for i in range(n + 2)]

    for i in range(n - 1):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    leafs = [-1] * (n + 2)

    dfs(1, -1)

    q = int(input())

    for i in range(q):
        qa, qb = map(int, input().split())
        output(f'{leafs[qa] * leafs[qb]}\n')

if __name__ == "__main__":
    for i in range(int(input())):
        solve()
