import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def solve():
    n = int(input())
    res = [['.' for _ in range(20)] for _ in range(10)]

    for i in range(n):
        s = input()
        row = ord(s[0]) - 65
        column = int(s[1:]) - 1
        res[row][column] = 'o'

    for i in res:
        print(*i, sep='')

if __name__ == "__main__":
    solve()
