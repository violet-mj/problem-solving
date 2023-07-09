import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, k = map(int, input().split())
    L = []

    for i in range(n):
        a, b = map(int, input().split())
        L.append((a, b))

    count = 0

    for aa, bb in L:
        count += bb

    L.sort(key=lambda x: x[0])
    LL = [(L[0][0], count)]
    

    for i in range(1, n):
        LL.append((L[i][0], count - L[i-1][1]))
        count -= L[i-1][1]


    if LL[0][1] <= k:
        return 1

    for i in range(1, n):
        if LL[i][1] <= k:
            return LL[i-1][0] + 1

    return LL[-1][0] + 1

if __name__ == "__main__":
    print(solve())
