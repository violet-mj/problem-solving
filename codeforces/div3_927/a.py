import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    L = input().split('**')
    max_ = 0
    for l in L:
        max_ = max(max_, l.count('@')) 
    print(max_)

if __name__ == "__main__":
    for i in range(int(input())):
        solve()
