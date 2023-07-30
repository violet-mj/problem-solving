import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())

def solve():
    n = int(input())
    L = list(mii())

    curr = [-1, -1]

    min_ = min(L)
    max_ = max(L)

    if min_ == 0 and max_ == 0:
        print(0)
        return
    
    result = []

    for i in range(n):
        if L[i] < 0:
           currMin = [L[i], i] 
           break

    for i in range(n - 1, -1, -1):
        if L[i] > 0:
            curr = [L[i], i]
            break

    if curr[0] > 0:
        while L[curr[1]] <= 3:
            L[curr[1]] += curr[0]
            curr[0] = L[curr[1]]
            result.append((curr[1]+1, curr[1]+1))

        if curr[1] == 0:
            curr = [L[0], 0]
        else:
            while L[curr[1]] >= L[0]:
                L[0] += L[curr[1]]
                result.append((1, curr[1]+1))
            curr = [L[0], 0]

        for i in range(n-1):
            if L[i+1] < L[i]:
                while L[i+1] < L[i]:
                    L[i+1] += curr[0]
                    result.append((i+2, curr[1]+1)) curr = [L[i+1], i+1]
                
    elif curr[0] < 0:
        while L[currMin[1]] >= -3:
            L[currMin[1]] += currMin[0]
            currMin[0] = L[currMin[1]]
            result.append((currMin[1] + 1, currMin[1] + 1))

        if currMin[1] == n -1:
            currMin = [L[-1], n-1]
        else:
            while L[-1] >= L[currMin[1]]:
                L[-1] += currMin[0]
                result.append((n, currMin[1] + 1))
            currMin = [L[-1], n-1]

        for i in range(n-1, 0, -1):
            if L[i] < L[i-1]:
                while L[i] < L[i-1]:
                    L[i-1] += currMin[0]
                    result.append((i, currMin[1] + 1))
                currMin = [L[i-1], i-1]

    print(len(result))
    for a, b in result:
        print(a, b)
    
if __name__ == "__main__":
    for i in range(int(input())):
        solve()
