import sys
from string import ascii_lowercase
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())


def solve():
    n, tp = input().split()
    n = int(n)
    tps = len(tp)

    res = []

    for i in range(n):
        tmp = input()

        if len(tmp) > tps + 1 or len(tmp) < tps - 1:
            continue
        
        if len(tmp) == tps + 1:
            error = 0
            j = 0
            flag = True
            while j + error < tps + 1 and j < tps:
                if tmp[j+error] == tp[j]:
                    j+=1
                    continue
                else:
                    error+=1
                if error > 1:
                    flag = False
                    break
            if flag: res.append(i + 1)
            continue

        if len(tmp) == tps:
            error = 0
            for idx, j in enumerate(tmp):
                if j != tp[idx]:
                    error += 1
            if error <= 1:
                res.append(i+1)
            continue

        if len(tmp) == tps - 1:
            error = 0
            j = 0
            flag = True
            while j + error < tps and j < tps - 1:
                if tmp[j] == tp[j+error]:
                    j+=1
                    continue
                else:
                    error+=1
                if error > 1:
                    flag = False
                    break
            if flag: res.append(i + 1)
            continue

    return res
if __name__ == "__main__":
    res = solve()
    print(len(res))
    for i in res:
        print(i, end = " ")
