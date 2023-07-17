import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, k = map(int, input().split())
    L = list(map(int, input().split()))

    k1 = [0] * (n + 1)
    k2 = [[-1 for i in range(2)] for i in range(n + 1)]  

    for idx, i in enumerate(L):
        if idx - k1[i] >  k2[i][1]:
            k2[i] = [k2[i][1], idx - k1[i]]
        else:
            if idx - k1[i] > k2[i][0]:
                k2[i][0] = idx - k1[i]

        k1[i] = idx + 1


    for i in range(1, k + 1):
        if n- k1[i] >  k2[i][1]:
            k2[i] = [k2[i][1], n - k1[i]]
        else:
            if n - k1[i] > k2[i][0]:
                k2[i][0] = n - k1[i]

    min_ = sys.maxsize

    for prev, curr in k2:
        k = max(curr // 2, prev)
        if k != -1:
            min_ = min(min_, k)

    return min_







if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
