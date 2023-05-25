import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, m = map(int, input().split())
    k = []

    for i in range(n):
        s = input()
        num = 0
        for idx, i in enumerate(s):
            num += int(i == 'o') * 2 ** (m - idx - 1)
        k.append(num)
    result = 0
    for i in range(n):
        for j in range(i + 1, n):
            if k[i] | k[j] == 2 ** m - 1:
                result += 1
    
    return result
if __name__ == "__main__":
    print(solve())
