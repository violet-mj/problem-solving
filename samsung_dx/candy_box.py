import sys
input = lambda: sys.stdin.readline().rstrip()

def check(value):
    global L
    k = 0
    for i in L:
        k += i // value
        if k >= m:
            return True
    
    return False

    

def solve(tn):
    global L, m
    n, m = map(int, input().split())
    L = list(map(int, input().split()))

    l = 0
    r = int(1e18) + 1

    while l + 1 < r:
        mid = (l + r) >> 1

        if check(mid):
            l = mid
        else:
            r = mid

    print(f'#{tn} {l}')

if __name__ == "__main__":
    for i in range(int(input())):
        solve(i+1)
