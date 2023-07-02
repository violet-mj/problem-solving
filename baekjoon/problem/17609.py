import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    s = input()
    l = 0
    r = len(s) - 1
    flag = True
    f1 = True
    k1 = -1

    while l < r:
        if s[l] == s[r]:
            l += 1
            r -= 1
        else:
            if flag:
                l += 1
                flag = False
            else:
                k1 = 2
                f1 = False
                break

    if f1:
        if flag:
            k1 = 0
        else:
            k1 = 1

    l = 0
    r = len(s) - 1
    k2 = -1

    flag = True
    f2 = True

    while l < r:
        if s[l] == s[r]:
            l += 1
            r -= 1
        else:
            if flag:
                r -= 1
                flag = False
            else:
                k2 = 2
                f2 = False
                break

    if f2:
        if flag:
            k2 = 0
        else:
            k2 = 1

    return min(k1, k2)


if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
