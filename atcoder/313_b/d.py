import sys
input = lambda: sys.stdin.readline().rstrip()
flush = sys.stdin.flush

mii = lambda: map(int, input().split())
ii = lambda: int(input())


def solve():
    n, k = mii()
    
    L = [*range(1, k)]
    result = [0] * (n + 1)
    query = ()
    kk = []
    
    for i in range(k, n + 1):
        print(f"? {' '.join(map(str, L))} {i}")
        flush()
        a = ii()
        result[i] = a
        kk.append(a)

    result2 = [*result]
    for i in range(k, n + 1):
        result2[i] ^= 1

    for i in range(k-1, 0, -1):
        print(f"? {' '.join(map(str, range(i, i + k)))}")
        flush()
        a = ii()
        asdf1 = sum(result[i+1:i+k]) % 2
        asdf2 = sum(result2[i+1:i+k]) % 2
        result[i] = a ^ asdf1
        result2[i] = a ^ asdf2

    ch = 0
    for i in range(1, k):
        ch += result[i]
    flag = True
    for idx, i in enumerate(kk):
        nextLoc = k + idx 
        if (ch + result[nextLoc]) % 2 == i:
            flag = False
            break
    if not flag:
        print(f"! {' '.join(map(str, result[1:]))}")
        return

    ch = 0
    for i in range(1, k):
        ch += result2[i]
    flag = True
    for idx, i in enumerate(kk):
        nextLoc = k + idx
        if (ch + result2[nextLoc]) % 2 == i:
            flag = False
            break
    if flag:
        print(f"! {' '.join(map(str, result2[1:]))}")
        return

if __name__ == "__main__":
    solve()
