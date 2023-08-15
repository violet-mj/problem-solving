import sys
from math import sqrt
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())

    sqrtn = int(n ** (1/2))

    result = set()

    if sqrtn ** 2 == n:
        return -1

    for i in range(1, sqrtn + 1):
        j = n - i ** 2
        sqrtj = sqrt(j)
        if sqrtj == int(sqrtj):
            isqrtj = int(sqrtj)
            if i > sqrtj:
                result.add((isqrtj, i))
            else:
                result.add((i, isqrtj))

    for i in range(1, sqrtn + 1):
        if n % i != 0: continue
        
        revi = n // i


        revi1 = revi - i
        revi2 = revi + i
            
        if revi1 % 2 == 0 and revi1 > 0 and revi2 > 0:
            revi1d = revi1//2
            revi2d = revi2//2
            result.add((min(revi1d, revi2d), max(revi1d, revi2d)))


        revi1 = i - revi
        revi2 = i + revi
            
        if revi1 % 2 == 0 and revi1 > 0 and revi2 > 0:
            revi1d = revi1//2
            revi2d = revi2//2
            result.add((min(revi1d, revi2d), max(revi1d, revi2d)))
    
    return len(result)

if __name__ == "__main__":
    print(solve())
