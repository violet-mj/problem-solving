import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    l = [list(input()) for i in range(8)]

    s = ''
    for i in range(8):
        for j in range(8):
            if l[j][i] != '.':
                s += l[j][i]
    
    return s
    
if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
