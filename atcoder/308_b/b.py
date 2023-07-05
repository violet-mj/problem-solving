import sys
from collections import defaultdict
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, m = map(int, input().split())
    ate = input().split()
    k = input().split()
    dic = defaultdict(int)
    for idx, i in enumerate(k):
        dic[i] = idx + 1

    price = list(map(int, input().split()))

    result = 0
    for a in ate:
        result += price[dic[a]]

    print(result)





if __name__ == "__main__":
    solve()
