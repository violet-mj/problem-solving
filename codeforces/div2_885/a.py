import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, m, k = map(int, input().split())
    x, y = map(int, input().split())
    L = [list(map(int, input().split())) for i in range(k)]
    for a, b in L:
        if (abs(x - a) + abs(y - b)) % 2 == 0:
            return "No"
    return "Yes"

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
