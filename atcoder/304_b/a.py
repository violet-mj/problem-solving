
import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())

    if abs(n - n // 5 * 5) >  abs((n // 5 + 1) * 5 - n):
        print((n // 5 + 1) * 5)
    else:
        print(n // 5 * 5)

if __name__ == "__main__":
    solve()
