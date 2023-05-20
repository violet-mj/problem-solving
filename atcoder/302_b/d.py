
import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def binarySearch(left, start, end):
    global n, m, d, A, B, max_

    initStart = start

    while start + 1 < end:
        mid = (start + end) // 2

        if B[mid] - A[left] <= d:
            start = mid
        else:
            end = mid


    if initStart == start:
        return

    max_ = max(B[start] + A[left], max_)


def solve():
    global n, m, d, A, B, max_
    n, m, d = map(int, input().split())
    A = list(map(int,input().split()))
    B = list(map(int,input().split()))

    A.sort()
    B.sort()

    l = 0
    r = 0
    max_ = -1

    while l < len(A):
        while r < len(B):
            if A[l] <= B[r]:
                break
            else:
                r+=1
        
        if r >= 1:
            if -d <= B[r-1] - A[l] < 0:
                max_ = max(A[l] + B[r-1], max_)

        if r != len(B):
            binarySearch(l, r - 1, len(B))
        
        l+=1
    
    print(max_)
        





if __name__ == "__main__":
    solve()
