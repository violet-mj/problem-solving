import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write
MOD = int(1e9 + 7)

def mul(a, b, mod):
    if b == 0:
        return 1
    
    divide = mul(a, b // 2, mod)

    if b % 2 == 1:
        return divide * divide * a % mod
    else:
        return divide * divide % mod

def solve():
    a, b, c = map(int, input().split())
    k = mul(b, c, MOD - 1)
    result = mul(a, k, MOD)

    return result

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
