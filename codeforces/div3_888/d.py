import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    L = list(map(int, input().split()))


    s = 0
    ss = set([i for i in range(1, n + 1)])

    sum_ = n * (n + 1) // 2

    if L[-1] > sum_:
        return "NO"

    s = 0
    if L[0] not in ss:
        s += L[0]
    else:
        ss.remove(L[0])

    for i in range(n-2):
        if L[i+1] - L[i] not in ss:
            s +=  L[i+1] - L[i]
        else:
            ss.remove(L[i+1] - L[i])

    if L[-1] != sum_:
        if sum_ - L[-1] in ss and len(ss) == 1:
            return "YES"
        else:
            return "NO"
    else:
        if sum(ss) == s and len(ss) == 2:
            return "YES"
        else:
            return "NO"



if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
