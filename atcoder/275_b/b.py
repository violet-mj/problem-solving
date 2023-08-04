
import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

MOD = 998244353

def solve():
    L = list(mii())
    L = map(lambda key: key % MOD, L)

    a,b,c,d,e,f=L

    ab = a*b%MOD
    abc = ab*c%MOD
    de = d*e%MOD
    def_ = de*f%MOD

    return (abc - def_) % MOD


if __name__ == "__main__":
    print(solve())
