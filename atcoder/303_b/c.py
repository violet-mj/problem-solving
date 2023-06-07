import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, m, h, k = map(int, input().split())
    s = input()

    x = []
    y = []
    
    for i in range(m):
        xi, yi = map(int, input().split())
        x.append(xi)
        y.append(yi)





if __name__ == "__main__":
    solve()
