import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    i = 1
    while((i * (i + 1) >> 1) <= n): i+=1
    print(i)
    remain = n - (i * (i - 1) >> 1)
    hope = i + 2 - remain
    if (i+2) ^ 0: remain, hope = hope, remain
    return f"{hope}/{remain}"
if __name__ == "__main__":
    print(solve())
