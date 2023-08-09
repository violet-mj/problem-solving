import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())


def solve():
    n = input()
    ns = list(n)
    ns = [*map(int, ns)][::-1] + [0]
    nineth = False


    check = -1
    for i in range(1, len(ns)):
        if ns[i] < 9 and nineth:
            ns[i] += 1
            nineth = False
        elif ns[i] == 9 and nineth:
            ns[i] = 0
            continue

        if ns[i] == 9:
            if ns[i-1] >= 5:
                nineth = True
                ns[i] = 0
                check = i-1
                continue
            else:
                continue

        if ns[i-1] >= 5:
            ith = ns[i] + 1
            ns[i] =  ith
            check = i-1

    for i in range(check+1):
        ns[i] = 0

    print(int(''.join(map(str, ns[::-1]))))

if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        solve()
