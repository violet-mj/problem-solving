import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    a, b = map(int, input().split())
    a -= 1
    b -= 1

    if a // 3 == b // 3:
        if b % 3 - a % 3 == 1:
            return "Yes"

    return "No"

if __name__ == "__main__":
    print(solve())
