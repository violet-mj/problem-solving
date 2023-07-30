import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())

def solve():
    n = int(input())

    for i in range(1, 1000000):
        if n % i != 0:
            return i - 1

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())

