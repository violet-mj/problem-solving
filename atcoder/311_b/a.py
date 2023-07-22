import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    s = input()

    k = set()

    for idx, i in enumerate(s, start=1):
        if len(k) == 3:
            return idx - 1
        k.add(i)

    if len(k) == 3:
        return n

if __name__ == "__main__":
    print(solve())
