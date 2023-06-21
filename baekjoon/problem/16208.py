import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    L = [*map(int, input().split())]
    initL = sum(L)
    L.sort()
    result = 0

    for i in L[:-1]:
        result += i * (initL - i)
        initL -= i
    
    print(result)

if __name__ == "__main__":
    solve()
