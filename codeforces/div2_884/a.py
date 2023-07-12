import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    a, b = map(int, input().split())
    print(a + b)

if __name__ == "__main__":
    for i in range(int(input())):
        solve()
