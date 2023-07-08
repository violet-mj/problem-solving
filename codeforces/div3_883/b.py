import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    graph = [list(input()) for i in range(3)]

    if graph[0][0] == graph[0][1] and graph[0][1] == graph[0][2] and graph[0][0] == graph[0][2]:
        if graph[0][0] != '.':
            return graph[0][0]

    if graph[1][0] == graph[1][1] and graph[1][1] == graph[1][2] and graph[1][0] == graph[1][2]:
        if graph[1][0] != '.':
            return graph[1][0]

    if graph[2][0] == graph[2][1] and graph[2][1] == graph[2][2] and graph[2][0] == graph[2][2]:
        if graph[2][0] != '.':
            return graph[2][0]

    if graph[0][0] == graph[1][0] and graph[1][0] == graph[2][0] and graph[0][0] == graph[2][0]:
        if graph[0][0] != '.':
            return graph[0][0]

    if graph[0][1] == graph[1][1] and graph[1][1] == graph[2][1] and graph[0][1] == graph[2][1]:
        if graph[0][1] != '.':
            return graph[0][1]

    if graph[0][2] == graph[1][2] and graph[1][2] == graph[2][2] and graph[0][2] == graph[2][2]:
        if graph[0][2] != '.':
            return graph[0][2]

    if graph[0][0] == graph[1][1] and graph[1][1] == graph[2][2] and graph[0][0] == graph[2][2]:
        if graph[0][0] != '.':
            return graph[0][0]
    
    if graph[0][2] == graph[1][1] and graph[1][1] == graph[2][0] and graph[0][2] == graph[2][0]:
        if graph[0][2] != '.':
            return graph[0][2]
    
    return "DRAW"
    
if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
