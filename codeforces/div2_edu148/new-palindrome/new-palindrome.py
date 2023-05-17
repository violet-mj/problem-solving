import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    s = input()

    checkIdx = len(s) // 2

    init = s[0]

    for i in range(1, checkIdx):
        if s[i] != init:
            return "YES"
    
    return "NO"

if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        print(solve())
