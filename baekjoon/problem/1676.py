import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())


def solve():
    n = int(input())

    cnt = [0, 0]

    for i in range(1, n + 1):
        k = i

        while(k % 2 == 0):
            k //= 2
            cnt[0] += 1

        while(k % 5 == 0):
            k //= 5
            cnt[1] += 1

    return min(cnt)

if __name__ == "__main__":
    print(solve())
