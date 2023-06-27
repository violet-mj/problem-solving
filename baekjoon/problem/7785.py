import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    a = set()

    for i in range(n):
        who, action = input().split()

        if action == 'enter':
            a.add(who)
        else:
            a.remove(who)

    A = list(a)
    A.sort(reverse=True)

    print(*A, sep="\n")

if __name__ == "__main__":
    solve()
