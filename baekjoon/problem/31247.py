import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n, k = map(int, input().split())
    k+=1; k = min(60, k)
    print(n // (1 << k))

if __name__ == "__main__":
    for i in range(int(input())):
        solve()
