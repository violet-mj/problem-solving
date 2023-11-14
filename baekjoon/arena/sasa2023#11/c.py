import sys
mii = lambda: map(int, input().split())
ii = lambda: int(input())

def solve():
    k = 100
    s = '2' * k

    t = ii()

    res = ''

    for i in range(k):
        tmp = '2' * (i) + '0' + '2' * (k - 1 - i)
        print(f'? {tmp}', flush=True)
        cnt = ii()

        if(cnt > t):
            res += '2'
        elif(cnt == t):
            res += '0'
        else:
            res += '5'

    print(f'! {res}', flush=True)

if __name__ == "__main__":
    solve()
