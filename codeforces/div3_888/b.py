import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    L = list(map(int, input().split()))

    odd = []
    oi = []
    even = []
    ei = []

    newL = [0] * n

    for idx, i in enumerate(L):
        if i % 2 == 0:
            even.append(i)
            ei.append(idx)
        else:
            odd.append(i)
            oi.append(idx)

    odd.sort()
    oi.sort()
    even.sort()
    ei.sort()

    for i in range(len(odd)):
        newL[oi[i]] = odd[i]

    for i in range(len(even)):
        newL[ei[i]] = even[i]
    L.sort()

    if newL == L:
        return "YES"
    else:
        return "NO"


    
    


if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
