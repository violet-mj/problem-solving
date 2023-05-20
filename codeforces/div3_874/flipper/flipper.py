import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write
 
 
def solve():
    global n, L, resultL, strL
    n = int(input())
    L = list(map(int, input().split()))
 
    if n == 1:
        return L
 
    k = max(L[1:])
 
    r = L.index(k)
 
    resultL = [0] * n
    if r == n - 1:
        l = r
        for i in range(l, -1, -1):
            segment = L[i:r+1]
            final = [*reversed(segment)] + L[:i]
 
            if final > resultL:
                resultL = final
    else:
 
        r -= 1
        l = r
 
        for i in range(l, -1, -1):
            segment = L[i:r+1]
            final = L[r+1:] + [*reversed(segment)] + L[:i]
 
            if final > resultL:
                resultL = final
 
    return resultL
 
 
if __name__ == "__main__":
    for i in range(int(input())):
        print(*solve())
