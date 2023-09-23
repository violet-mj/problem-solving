import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def solve():
    n = input()
    init = n[0]
    for i in range(1, len(n)):
        if n[i]  < init:
            init = n[i]
        else:
            return "No"
    return "Yes"

if __name__ == "__main__":
    print(solve())
