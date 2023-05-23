import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write
MOD = int(998244353)

def mul(a, b, mod):
    if b == 0:
        return 1
    
    divide = mul(a, b // 2, mod)

    if b % 2 == 1:
        return divide * divide * a % mod
    else:
        return divide * divide % mod

def solve():
    result = mul(8, MOD - 2, MOD)


    return result * 7 % MOD

if __name__ == "__main__":
    print(solve())
