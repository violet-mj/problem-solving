
import sys
from datetime import date
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def toDate(currDate):
    y, m, d = map(int, currDate.split('-'))
    return date(y, m, d)

def solve():
    currDate = input()

    n = int(input())

    cnt = 0

    for i in range(n):
        checkDate = input()

        if currDate <= checkDate:
            cnt += 1

    return cnt


if __name__ == "__main__":
    print(solve())
