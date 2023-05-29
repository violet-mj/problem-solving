
import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    print(*range(n, 0, -1), sep="\n")

if __name__ == "__main__":
    solve()
