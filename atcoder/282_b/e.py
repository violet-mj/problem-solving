import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def mul(a, b, m):
    if b == 0:
        return 1
    
    divide = mul(a, b // 2, m)

    if b % 2 == 1:
        return divide * divide * a % m
    else:
        return divide * divide % m

def solve():
    n, m = map(int, input().split())
    L = [*map(int, input().split())]

    L.sort(reverse=True)

    result = 0

    for i in range(n-1):
        a = L[i]
        b = L[i+1]
        r = (mul(a, b, m) + mul(b, a, m)) % m
        result += r
        result

    return result

if __name__ == "__main__":
    print(solve())
