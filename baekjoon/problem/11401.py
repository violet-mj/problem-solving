import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write
MOD = int(1e9+7)

def mul(a, b):
    if b == 0:
        return 1
    
    divide = mul(a, b // 2)
    
    if b % 2 == 1:
        return divide * divide * a % MOD
    else:
        return divide * divide % MOD

def solve():
    n, k = map(int, input().split())

    L = [1]

    for i in range(1, n+1):
        L.append(L[-1] * i % MOD)

    return L[n] * mul(L[n - k] * L[k] % MOD, MOD - 2) % MOD

if __name__ == "__main__":
    print(solve())
