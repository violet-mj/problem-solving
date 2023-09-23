import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())


def solve():
    cn = int(input())
    cnL = set(input().split())
    nn = int(input())
    nnL = set(input().split())
    an = int(input())
    anL = set(input().split())
    rnL = (cnL | nnL) - anL
    n = int(input())
    s = input()
    s = s.split()

    for i in rnL:
        k = []
        for j in s:
            k += j.split(i)
        s = k

    res = []
    for i in s:
        if i != '':
            res.append(i)

    return res

if __name__ == "__main__":
    print(*solve(), sep="\n")
