
import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    L = [*map(int, input().split())]
    L.sort()
    return L

if __name__ == "__main__":
    print(*solve())
