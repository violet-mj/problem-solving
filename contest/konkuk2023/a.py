import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def solve():
    n, m = mii()
    check = [0 for i in range(502)]
    
    for i in range(n):
        s = input()
        s = s.split('0')
        cnt = 0
        for j in s:
            if j != '':
                cnt+=1
        check[cnt]+=1

    for i in range(501, -1, -1):
        if check[i] != 0:
            print(i, check[i])
            return

if __name__ == "__main__":
    solve()
