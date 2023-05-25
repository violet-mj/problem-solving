import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    s = input()
    pif = 0
    rs = []

    for i in s:
        if i == '\"':
            pif += 1
        elif i == ',':
            if pif % 2 == 0:
                rs.append('.')
                continue
        rs.append(i)
    print(''.join(rs))




if __name__ == "__main__":
    solve()
