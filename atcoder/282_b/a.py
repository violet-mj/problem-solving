import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    s = ''

    for i in range(n):
        s += chr(65 + i)

    return s
if __name__ == "__main__":
    print(solve())
