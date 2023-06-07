import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    s = input()
    init = None
    result = ''

    for i in range(len(s)):
        if init == None:
            init = s[i]
            continue
        if s[i] == init:
            result += init
            init = None
    print(result)

if __name__ == "__main__":
    for i in range(int(input())):
        solve()
