import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def solve():
    b = int(input())

    for i in range(1, 18):
        if i ** i == b:
            return i

    return -1

if __name__ == "__main__":
    print(solve())
