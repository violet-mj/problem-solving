import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    a, b, c = map(int, input().split())

    if a + b >= 10 or b + c >= 10 or a + c >= 10:
        return "YES"

    return "NO"

    
if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
