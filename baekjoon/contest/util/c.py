import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def plus(curr):
    cnt = 0
    if(curr >= 60): cnt += 1
    if(curr >= 100): cnt+= 1
    if(curr >= 140): cnt+= 1
    if(curr >= 200): cnt+= 1
    if(curr >= 250): cnt+= 1
    
    return cnt

def solve():
    n = int(input())
    cnt = 0 
    power = 0
    L = [int(input()) for i in range(n)]
    L.sort(reverse=True)
    L = L[:42]
    for curr in L:
        cnt += plus(curr)
        power += curr

    return (power, cnt)

if __name__ == "__main__":
    print(*solve())
