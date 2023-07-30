import sys
input = lambda: sys.stdin.readline().rstrip()

mii = lambda: map(int, input().split())
ii = lambda: int(input())

def solve():
    st = set(['ACE', 'BDF', 'CEG', 'DFA', 'EGB', 'FAC', 'GBD'])

    s = input()

    return "Yes" if s in st else "No"

if __name__ == "__main__":
    print(solve())
