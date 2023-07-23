import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write






def solve():
    n = int(input())
    L = list(map(int, input().split()))

    prime = []
    num = [True] * (n + 1)
    m = int(n ** 0.5)
    num[1] = False
    for i in range(2, m + 1):
        if num[i] == True:
            for j in range(i + i, n+1, i):
                num[j] = False

    for i in range(1, n + 1):
        if num[i]:
            prime.append(i)

    oneCount = 0

    for i in L:
        if i == 1:
            oneCount += 1

    result = 0
    for i in prime:
        c = 0
        for j in L:
            if j <= n and j % i == 0:
                c += 1
        result = max(result, c)

    return result + oneCount
    
if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
