import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def solve():
    n = ii()
    L = list(mii())

    L.sort()
    Ll = len(L)
    sL = sum(L) // Ll

    Lr = sum(L) % Ll

    check = [sL] * (Ll - Lr) + [sL + 1] * Lr


    res1 = 0
    for i in range(n-1, -1, -1):
        if check[i] < L[i]:
            res1 += L[i] - check[i]
        else:
            break

    return res1 



if __name__ == "__main__":
    print(solve())
