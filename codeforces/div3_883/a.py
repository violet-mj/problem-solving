import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())

    result = 0

    for i in range(n):
        a, b = map(int, input().split())

        if a - b > 0:
            result += 1

    return result


if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
