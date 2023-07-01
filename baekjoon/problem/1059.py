import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    L = list(map(int, input().split()))
    target = int(input())

    L.sort()

    if target < L[0]:
        return (target) * (L[0] - target) - 1

    for i in range(n - 1):
        if L[i] <= target <= L[i+1]:
            if L[i] == target or L[i+1] == target:
                return 0
            return (target - L[i]) * (L[i + 1] - target) - 1
    return (target - L[-1]) * (1000 - target) - 1

if __name__ == "__main__":
    print(solve())
