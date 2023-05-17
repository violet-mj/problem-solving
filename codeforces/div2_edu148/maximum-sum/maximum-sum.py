import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, k = map(int, input().split())

    maxValue = -1
    
    L = [*map(int, input().split())]
    L.sort()

    prefixSum = [0, L[0]]

    for i in range(1, n):
        prefixSum.append(prefixSum[-1] + L[i]) 

    for i in range(k + 1):
        maxValue = max(maxValue, prefixSum[n - (k - i)] - prefixSum[2 * i])
    
    return maxValue




if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        print(solve())
