import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    L = [*map(int, input().split())]

    oneIndex = -1
    twoIndex = -1
    maxIndex = -1
    maxMIndex = -1

    for i in range(n):
        if L[i] == n:
            maxIndex = i
        elif L[i] == n-1:
            maxMIndex = i

    for idx, i in enumerate(L):
        if i == 1:
            oneIndex = idx
            if oneIndex == 0:
                return (oneIndex + 2, maxIndex + 1)
            elif oneIndex == n - 1:
                return (oneIndex, maxIndex + 1)
            else:
                if L[oneIndex - 1] > L[oneIndex + 1]:
                    if L[oneIndex - 1] == n:
                        return (oneIndex + 2, maxMIndex + 1)
                    else:
                        return (oneIndex + 2, maxIndex + 1)
                else:
                    if L[oneIndex + 1] == n:
                        return (oneIndex, maxMIndex + 1)
                    else:
                        return (oneIndex, maxIndex + 1)

if __name__ == "__main__":
    for i in range(int(input())):
        print(*solve())
