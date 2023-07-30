import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def solve():
    n, m = mii()

    result = []
    graph = [input() for i in range(n)]

    for i in range(n-8):
        for j in range(m-8):
            if graph[i][j:j+4] == '###.' and graph[i+1][j:j+4] == '###.' and graph[i+2][j:j + 4] == '###.' and graph[i+3][j:j+4] == '....':
                if graph[i+5][j+5:j+9] == '....' and graph[i+6][j+5:j+9] == '.###' and graph[i+7][j+5:j+9] == '.###' and graph[i+8][j+5:j+9] == '.###':
                    result.append((i+1, j+1))
        
    for a, b in result:
        print(a, b)

if __name__ == "__main__":
    solve()
