import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

signSet = set(['|', '*'])

def solve():
    n = int(input())
    s = input()

    st = ''

    for i in s:
        if i in signSet:
            st += i

    if st == '|*|':
        return 'in'
    else:
        return 'out'


if __name__ == "__main__":
    print(solve())

