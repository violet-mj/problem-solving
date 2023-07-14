import sys
from collections import defaultdict
input = lambda: sys.stdin.readline().rstrip()

def solve():
    a, p = map(int, input().split())
    k = [a]
    while True:
        b = str(a)

        result = 0

        for i in b:
            result += int(i) ** p

        a = result

        if a in k:
            return k.index(a)
        k.append(a)

    return len(k)
        



if __name__ == "__main__":
    print(solve())
