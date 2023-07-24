dic = {
    '/': lambda x, y: x / y,
    '*': lambda x, y: x * y,
    '+': lambda x, y: x + y,
    '-': lambda x, y: x - y
}

def dfs(curr):
    global n, graph, node
    if node[curr].isdigit():
        return int(node[curr])
    left = dfs(int(graph[curr][0]))
    right = dfs(int(graph[curr][1]))
    return dic[node[curr]](left, right)

def solve():
    global n, graph, node
    n = int(input())
    graph = [[] for i in range(n + 1)]
    node = ['' for i in range(n + 1)]

    for i in range(n):
        curr, sign, *child = input().split()
        curr = int(curr)
        graph[curr] = graph[curr] + child
        node[curr] = sign

    return dfs(1)

if __name__ == "__main__":
    for i in range(1, 2):
        print(f'#{i} {solve()}')
