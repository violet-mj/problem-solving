import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, m, h = map(int, input().split()) 

    L = list(map(int, input().split()))
    L.sort()
    first = 0
    count = 0
    result = 1
    penalty = 0
    for i in L:
        if first + i <= h:
            penalty += (first + i)
            first += i
            count += 1
        else:
            break

    for i in range(n-1):
        a = list(map(int, input().split()))
        a.sort()
        tmp = 0
        c = 0
        p = 0
        for i in a:
            if tmp + i <= h:
                p += (tmp + i)
                tmp += i
                c += 1
            else:
                break

        if c > count or (c == count and p < penalty):
            result += 1

    return result

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
