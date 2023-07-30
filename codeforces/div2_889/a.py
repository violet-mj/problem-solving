import sys
from math import ceil
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())

def solve():
    n = int(input())
    L = list(mii())

    count = 0
    
    for idx, i in enumerate(L, start = 1):
        if idx == i:
            count += 1

    return ceil(count / 2)




if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
