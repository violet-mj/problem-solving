import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write


def solve():
    n, t = map(int,input().split())
    index = [i for i in range(1, n + 1)]
    C = list(map(int,input().split()))
    R = list(map(int,input().split()))

    if t not in C:
        t = C[0]

    cr = [*zip(C, R, index)]
    result = []
    for i in range(n):
        if cr[i][0] == t:
            result.append(cr[i])

    result.sort(key=lambda x: x[1], reverse=True)

    return result[0][2]

if __name__ == "__main__":
    print(solve())

