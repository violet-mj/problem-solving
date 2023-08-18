import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())


def gcd(a, b):
    while b:
        a %= b
        a, b = b, a
    return a

def solve():
    n = int(input())

    ss = set()

    for i in range(n):
        x, y = mii()


        if x == 0:
            ss.add((0, y // abs(y)))
            continue

        if y == 0:
            ss.add((x // abs(x), 0))
            continue
        
        g = gcd(abs(x), abs(y))
        ss.add((x//g, y//g))
    
    return len(ss)


if __name__ == "__main__":
    print(solve())
