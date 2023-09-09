import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def solve():
    s = input()
    DKSH = 'DKSH'
    cnt = 0
    for i in range(len(s) - 3):
        if s[i:i+4] == DKSH:
            cnt+=1

    return cnt
if __name__ == "__main__":
    print(solve())
