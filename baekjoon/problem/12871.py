import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def solve():
    s = input()
    t = input()

    ss = len(s)
    ts = len(t)

    lcmSt = ss * ts // gcd(ss, ts)

    if s * (lcmSt // ss) == t * (lcmSt // ts):
        return 1
    else:
        return 0

if __name__ == "__main__":
    print(solve())
