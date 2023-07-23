import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, c = map(int, input().split())

    L = list(map(int, input().split()))

    Lsum = sum(L)

    Lssum = 0 

    for i in L:
        Lssum += i ** 2

    l = -1
    r = 10 ** 18

    while l + 1 < r:
        mid = (l + r) // 2
        
        k = n * (mid ** 2) + Lsum * 2 * mid + Lssum

        if k == c:
            return mid
        elif k < c:
            l = mid
        else:
            r = mid

    
if __name__ == "__main__":
    for i in range(int(input())):
        print(solve() // 2)
