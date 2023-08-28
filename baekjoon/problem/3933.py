import sys
from math import sqrt
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())


def solve():
    while(1):
        n = int(input())

        if n == 0: break
        cnt = 0

        for i in range(int(sqrt(n))):
            for j in range(int(sqrt(n))):
                for z in range(int(sqrt(n))):
                    for k in range(int(sqrt(n))):
                        if i ** 2 + j ** 2 + z ** 2 + k ** 2 == n:
                            cnt += 1
        print(cnt)

if __name__ == "__main__":
    solve()
