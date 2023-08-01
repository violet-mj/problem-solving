import sys
input = lambda: sys.stdin.readline().rstrip()

dx = [-1, 0, 1, 0]
dy = [0, 1, 0 ,-1]

def possible(cx, cy, dir_):
    global n, L, check, pos
    while 0 < cx < n-1 and 0 < cy < n-1:
        cx += dx[dir_]
        cy += dy[dir_]

        if pos[cx][cy] == 1:
            return False
    
    return True

def checking(cx, cy, dir_):
    global n, L, check, pos
    count = 0
    while 0 < cx < n-1 and 0 < cy < n - 1:
        cx += dx[dir_]
        cy += dy[dir_]

        pos[cx][cy] ^= 1

        count += 1

    return count 


def backtracking(cx, cy, count, index):
    global n, L, check, pos, min_, cl

    if index == cl - 1:
        for i in range(4):
            if possible(cx, cy, i):
                c = checking(cx, cy, i)
                min_ = min(min_, count + c)
                checking(cx, cy, i)
        return

    for i in range(4):
        if possible(cx, cy, i):
            c = checking(cx, cy, i)
            cx_, cy_ = check[index + 1]
            backtracking(cx_, cy_, count + c, index + 1)
            checking(cx, cy, i)

def solve(tn):
    global n, L, check, pos, min_, cl
    min_ = sys.maxsize
    n = int(input())
    L = [list(map(int, input().split())) for i in range(n)]

    check_ = []

    pos = [[0 for i in range(n)] for i in range(n)]

    for i in range(n):
        for j in range(n):
            if L[i][j] == 1:
                pos[i][j] = 1
                if i == 0 or i == n -1 or j == 0 or j == n-1:
                     continue
                check_.append((i, j))
    
    check = []

    for x, y in check_:
        count = 0
        for i in range(4):
            if not possible(x, y, i):
                count += 1
        if count != 4:
            check.append((x, y))

    cl = len(check)

    if cl == 0:
        return f'#{tn} {0}'
    
    cx, cy = check[0]
    backtracking(cx, cy, 0, 0)

    if min_ == float('inf'):
        min_ = 0

    return f'#{tn} {min_}'

if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        print(solve(i + 1))
