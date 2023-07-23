import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())

    l = []

    for i in range(n):
        a, b = map(int, input().split())

        if a <= 10:
            l.append((a, b, i+1))

    l.sort(key=lambda x: x[1], reverse=True)

    return l[0][2]
    
if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
