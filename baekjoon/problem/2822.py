import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())


def solve():
    L = [(int(input()), i+1) for i in range(8)]

    L.sort(reverse=True)
    L = L[:5]

    sum_ = 0

    for i in range(5):
        sum_ += L[i][0]

    print(sum_)

    res = []

    for i in range(5):
        res.append(L[i][1])
    res.sort()

    print(*res)


if __name__ == "__main__":
    solve()
