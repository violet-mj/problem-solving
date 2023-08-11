import sys
from collections import defaultdict
input = lambda: sys.stdin.readline().rstrip()

def mul(n):
    if n == 1: return 2

    div = mul(n // 2)
    divSquare = div ** 2

    return divSquare * 2 % MOD  if n % 2 == 1 else divSquare % MOD


def solve(tn):
    global MOD
    a, b, k = map(int, input().split())

    MOD = a + b

    res = (a * mul(k)) % MOD

    res = min(res, MOD - res)
    
    print(f'#{tn} {res}')

if __name__ == "__main__":
    for i in range(int(input())):
        solve(i+1)
