import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    result = n
    while n != 1:
        n //= 2
        result += n

    print(result)

if __name__ == "__main__":
    for i in range(int(input())):
        solve()
