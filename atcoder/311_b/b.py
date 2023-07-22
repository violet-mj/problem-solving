import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, m = map(int, input().split())
    graph = [list(input()) for i in range(n)]
    g = [*zip(*graph)]
    kk = []

    for i in range(m):
        kk.append(''.join(g[i]))

    k = 0
    result = 0
    for i in range(m):
        if kk[i] == 'o' * n:
            k += 1
        else:
            result = max(k, result)
            k = 0
    result = max(k, result)

    return result

if __name__ == "__main__":
    print(solve())
