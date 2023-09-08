import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())


def solve():
    N, M = mii()

    L1 = list(mii())
    L2 = list(mii())

    L1.sort()
    L2.sort()

    pos1 = 0
    pos2 = 0
    cnt1 = 0
    cnt2 = 0
    
    for i in  L1:
        if i >= pos1:
            cnt1+=1
            pos1 = i + 100
    
    for i in L2:
        if i >= pos2:
            cnt2+=1
            pos2 = i + 360

    print(cnt1, cnt2)

if __name__ == "__main__":
    solve()
