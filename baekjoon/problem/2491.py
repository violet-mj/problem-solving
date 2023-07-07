import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    L = list(map(int,input().split()))

    tmp = -sys.maxsize
    max_ = -sys.maxsize
    result = 0
    for i in range(n):
        if L[i] >= tmp:
            result += 1
        else:
            max_ = max(max_, result)
            result = 1
        tmp = L[i]

    max_ = max(max_, result)

    tmp = sys.maxsize
    result = 0

    for i in range(n):
        if L[i] <= tmp:
            result += 1
        else:
            max_ = max(max_, result)
            result = 1

        tmp = L[i]

    max_ = max(max_, result)

    return max_
if __name__ == "__main__":
    print(solve())
