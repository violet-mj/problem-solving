import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def solve():
    s = input()
    ss = len(s)
    max_ = 0

    for i in range(ss):
        for j in range(i+1, ss + 1):
            subString = s[i:j]
            flag=True
            sts = len(subString)
            cnt = 0
            dSts = sts//2 if sts % 2 == 0 else sts//2+1
            for z in range(dSts):
                if subString[z] == subString[sts-z-1]:
                    if z == sts-z-1:
                        cnt+=1
                    else:
                        cnt+=2
                else:
                    flag=False
                    break

            if flag:
                max_ = max(cnt, max_)

    return max_


if __name__ == "__main__":
    print(solve())
