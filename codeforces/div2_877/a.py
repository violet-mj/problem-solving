import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    L = [*map(int, input().split())]
    count = 0
    nega = []

    for i in range(n):
        if L[i] < 0:
            count += 1
            nega.append(L[i])

    if count > 2:
        return -1

    if len(nega) > 0:
        return nega[0]
    
    L.sort()

    return L[-1]

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())

