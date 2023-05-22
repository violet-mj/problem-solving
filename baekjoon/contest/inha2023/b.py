
import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def tracking(i, j, contribute, count):
    global m, n, k, result

    if count == n:
        if contribute >= m:
            result += 1
        return

    for ii in range(3):
        for jj in range(2):
            if ii == i:
                tracking(ii, jj, contribute + (k[jj][ii] // 2), count + 1)
            else:
                tracking(ii, jj, contribute + k[jj][ii], count + 1)


def solve():
    global m, n, k, result
    result=0
    n, m = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    k = [A, B]

    for i in range(3):
        for j in range(2):
            tracking(i, j, k[j][i], 1)

if __name__ == "__main__":
    solve()
    print(result)
