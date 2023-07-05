import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    L = list(map(int, input().split()))
    k = -1

    for i in L:
        if i >= k and 100 <= i <= 675 and i % 25 == 0:
            k = i
            continue
        else:
            return "No"

    return "Yes"


if __name__ == "__main__":
    print(solve())
