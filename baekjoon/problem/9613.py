
import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def gcd(a, b):
    while b != 0:
        a, b = b, a % b

    return a

def solve():
    n, *k = map(int, input().split())

    result = 0

    for i in range(n):
        for j in range(i + 1, n):
            result += gcd(k[i], k[j])

    return result

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
