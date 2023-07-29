import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n, k = map(int, input().split())
    L = list(map(int, input().split()))

    first = L[0]
    end = L[-1]

    fc = 0
    endc = 0

    fff = -1
    eee = -1

    for i in range(n):
        if L[i] == first:
            fc += 1
            if fc == k:
                fff = i
                break
    
    for i in range(n-1, -1, -1):
        if L[i] == end:
            endc += 1
            if endc == k:
                eee = i
                break
    
    if fc < k or endc < k:
        return "NO"

    if first == end:
        return "YES"

    if fff < eee:
        return "YES"
    else:
        return "NO"





if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
