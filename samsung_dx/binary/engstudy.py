import sys
input = lambda: sys.stdin.readline().rstrip()

def check(value):
    global n, p, L, prefixSum

    for i in range(value, 1200001):
        curr = prefixSum[i] - prefixSum[i-value]
        if p >= value - curr:
            return True

    return False


def solve(tn):
    global n, p, L, prefixSum
    n, p = map(int, input().split())
    L = list(map(int, input().split()))

    prefixSum = [0] * (1200001)

    for i in L:
        prefixSum[i] = 1

    for i in range(1, 1200001):
        prefixSum[i] = prefixSum[i-1] + prefixSum[i]

    l = 1
    r = 1200001

    while l + 1 < r:
        mid = (l + r) >> 1

        if check(mid):
            l = mid
        else:
            r = mid

    print(f'#{tn} {l}')

if __name__ == "__main__":
    for i in range(int(input())):
        solve(i+1)
