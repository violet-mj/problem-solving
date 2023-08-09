import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())


def solve(tn):
    n, m = map(int, input().split())

    A = input().split()
    B = input().split()

    As = set(A)
    Bs = set(B)

    print(f'#{tn} {len(As & Bs)}')
    

if __name__ == "__main__":
    t = int(input())

    for i in range(t):
        solve(i+1)
