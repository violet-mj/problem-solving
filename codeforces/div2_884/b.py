import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    L = [0] * n
    L[0] = 2
    L[-1] = 3
    L[n//2] = 1

    curr = n

    for i in range(1, n//2):
        L[i] = curr
        curr -= 1

    for i in range(n//2+1, n-1):
        L[i] = curr
        curr -= 1

    print(*L)



if __name__ == "__main__":
    for i in range(int(input())):
        solve()
