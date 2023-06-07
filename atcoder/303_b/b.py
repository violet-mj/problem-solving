import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, m = map(int, input().split())

    graph = []

    for i in range(m):
        graph.append([*map(int, input().split())])
    
    pairs = set()

    for i in range(1, n + 1):
        for j in range(i + 1, n + 1):
            pairs.add((i, j))

    for i in range(m):
        for j in range(n - 1):
            minV = min(graph[i][j], graph[i][j+1])
            maxV = max(graph[i][j], graph[i][j+1])

            pairs.discard((minV, maxV))
    
    return len(pairs)


if __name__ == "__main__":
    print(solve())
