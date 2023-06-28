import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    a = set()
    result = 0
    for i in range(n):
        s = input()
        if s == 'ENTER':
            result += len(a)
            a.clear()
        else:
            a.add(s)

    result += len(a)

    print(result)


        


if __name__ == "__main__":
    solve()
