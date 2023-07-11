import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write
MOD = int(1e9 + 7)

def mul(n, a):
    if a == 0:
        return 1

    mid = mul(n, a // 2) % MOD
    if a % 2 == 0:
        return mid * mid % MOD
    else:
        return n * mid * mid % MOD

def solve():
    n, a = map(int, input().split())

    init = n * mul(n, a) % MOD

    second = n * (n - 2) * mul(n, a-1) % MOD

    return (init + n * (second - (n - 2) * mul(n-1, a)))  % MOD

if __name__ == "__main__":
    print(solve())
