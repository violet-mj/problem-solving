import sys
from bisect import bisect_right, bisect_left
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def solve():
    n = int(input())
    A = [*map(int, input().split())]
    prefixSum=[ 0 ]

    for i in range(1, n):
        if i % 2 == 1:
            prefixSum.append(prefixSum[-1])
        else:
            prefixSum.append(prefixSum[-1] + A[i] - A[i-1])

    #print(prefixSum)
    Q = int(input())

    for i in range(Q):
        value = 0
        ql, qr = map(int, input().split())

        kl = bisect_right(A, ql) 
        kr = bisect_left(A, qr) - 1
        #print(f"#{i+1} {kl} {kr}")

        if kl % 2 == 0:
            value += A[kl] - ql
            #print(f"#{i+1} first value {A[kl] - ql}" )

        if kr % 2 == 1:
            value += qr - A[kr]
            #print(f"#{i+1} second value {qr - A[kr]}" )

        value += prefixSum[kr] - prefixSum[kl]
        print(value)

if __name__ == "__main__":
    solve()
