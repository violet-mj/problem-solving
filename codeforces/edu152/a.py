import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    b, c, h = map(int, input().split())
    ch = c + h

    if b > ch:
        return 2 * ch + 1
    else:
        return 2 * b - 1

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
