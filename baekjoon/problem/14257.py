import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def bitsoncount(x):
    return bin(x).count('1')

def solve():
    s, x = mii()

    k = s - x

    if k < 0:
        return 0

    check = k & (~x << 1)

    if check == k:
        y = bitsoncount(x)
        result = 1
        for i in range(y):
            result *= 2
        if(s==x): result -= 2
        return result
    
    return 0

if __name__ == "__main__":
    print(solve())
