
import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    a = set()
    a.add("ChongChong")
    for i in range(n):
        f, s = input().split()

        if f in a or s in a:
            a.add(f)
            a.add(s)
    print(len(a))


if __name__ == "__main__":
    solve()
