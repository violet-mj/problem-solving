import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    L = list(map(int, input().split()))

    sum_ = sum(map(abs, L))

    flag = False
    count = 0

    for i in L:
        if i > 0:
            if flag:
                count += 1
                flag = False
        elif i == 0:
            continue
        else:
            flag = True
    if flag:
        count += 1

    print(sum_, count)
        
        



if __name__ == "__main__":
    for i in range(int(input())):
        solve()
