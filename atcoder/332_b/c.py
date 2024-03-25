import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())


def solve():
    n, m = mii()
    s = input()
    sp = s.split('0')

    need = 0
    n2 = 0

    for i in sp:
        n1p = 0
        n2p = 0
        for j in i:
            if j == '1':
                n1p+=1
            else:
                n2p+=1
        need = max(n1p + n2p - m, need)
        n2 = max(n2, n2p)
    
    return max(need, n2)
if __name__ == "__main__":
    print(solve())
