import sys
from collections import defaultdict
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    s = input()
    d = defaultdict(int)
    for i in range(len(s)):
        d[s[i]] += 1

    result = [''] * len(s)

    for i in range(0, len(s), 2):
        if i + 1 >= len(s):
            result[i // 2] = s[i]
            continue
        else:
            if s[i] == s[i+1]:
                result[i // 2] = s[i]
                result[len(s) - i // 2 - 1] = s[i]
            else:
                return "I'm Sorry Hansoo"

    return ''.join(result)




if __name__ == "__main__":
    print(solve())
