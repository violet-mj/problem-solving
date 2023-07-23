import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, k = map(int, input().split())
    L = list(map(int, input().split()))
    L.sort()
    q = 1
    result = 1

    for i in range(1, n):
        if L[i] - L[i-1] <= k:
            q = q + 1

        if L[i] - L[i-1] > k:
            result = max(q, result)
            q=1

    result = max(q, result)
    return n - result 
    
if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
