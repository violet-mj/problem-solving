
import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n, m = map(int, input().split())
    x = input()
    s = input()

    cnt = 0
    while(cnt < 10):

        if(n < m): 
            x *= 2
            n *= 2
            cnt += 1
            continue

        for i in range(n - m + 1):
            if x[i:i+m] == s:
                return cnt

        x *= 2 
        n *= 2
        cnt += 1

    return -1

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
