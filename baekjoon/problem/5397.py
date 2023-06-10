import sys
import string
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    leftS = []
    rightS = []

    ss = string.ascii_letters + string.digits
    sSet = set(ss)

    for i in input():
        if i in sSet:
            leftS.append(i)
        elif i == '<':
            if len(leftS) != 0:
                leftp = leftS.pop()
                rightS.append(leftp)
        elif i == '>':
            if len(rightS) != 0:
                rightp = rightS.pop()
                leftS.append(rightp)
        else:
            if len(leftS) != 0:
                leftS.pop()
    rightS.reverse()

    print(''.join(leftS +rightS))


if __name__ == "__main__":
    for i in range(int(input())):
        solve()
