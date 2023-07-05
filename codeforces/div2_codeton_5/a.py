import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, m = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    sumA = sum(A)
    sumB = sum(B)

    if sumA > sumB:
        return "Tsondu"
    elif sumA < sumB:
        return "Tenzing"
    else:
        return "Draw"

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
