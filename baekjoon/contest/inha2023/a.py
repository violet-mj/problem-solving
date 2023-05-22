
import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    s = input()
    stringSet = set()
    MOBIS = 'MOBIS'

    for i in s:
        stringSet.add(i)

    for i in MOBIS:
        if i not in stringSet:
            return "NO"

    return "YES"

if __name__ == "__main__":
    print(solve())

