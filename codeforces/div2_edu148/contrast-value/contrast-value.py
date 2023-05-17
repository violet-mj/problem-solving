import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    result = n
    subtract = 0
    L = [*map(int, input().split())]
    empty = [False] * n

    if L.count(L[0]) == n:
        return 1

    if n == 1:
        return 1
    
    if n == 2:
        if L[0] == L[1]:
            return 1
        else:
            return 2

    start = 0
    middle = 1
    end = 2

    while end < n:
        if (L[end] <= L[middle] <= L[start]) or (L[start] <= L[middle] <= L[end]):
            result -= 1
            empty[middle] = True
        else:
            start += 1
            while True:
                if empty[start]:
                    start += 1
                else:
                    break
        middle += 1
        end += 1

    return result

if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        print(solve())

