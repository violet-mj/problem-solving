import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())


oper = {
    '*' : [0 for i in range(100001)],
    '/' : [0 for i in range(100001)]
}

def factorize(num, t):
    num = abs(num)
    nSqrt = int(num**.5) + 1
    i = 2
    while i <= nSqrt and num != 0:
        if num == 1: break
        while num % i == 0:
            oper[t][i]+=1
            num //= i
        i+=1

    if num != 1:
        oper[t][num]+=1

def solve():
    n = ii()
    L = ['*'] + input().split() 

    for i in range(1, len(L), 2):
        factorize(int(L[i]), L[i-1])

    flag = True

    for i in range(2, 100001):
        if oper['/'][i] > oper['*'][i]:
            flag = False
            break

    if oper['*'][0] > 0:
        flag = True

    return "mint chocolate" if flag else 'toothpaste'

if __name__ == "__main__":
    print(solve())
