import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write
 
def solve():
    n = int(input())
    L = list(map(int, input().split()))
    L.sort()
    minL = min(L)
 
    parity = 1 if minL % 2 == 1 else 0
 
    if not parity:
        for i in range(1, n):
            if L[i] % 2 != parity:
                return "NO"
        return "YES"
    else:
        return "YES"
 
if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
