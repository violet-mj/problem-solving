import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    s = input()
    k = []
    curr = s[0]
    count = 1

    for i in range(1, n):
        if curr != s[i]:
            k.append(curr * count)
            curr = s[i]
            count = 1
        else:
            count += 1
    k.append(curr * count)
    currValue = 1
    kk = [1]
    for i in k:
        if i[0] == '<':
            currValue -= len(i)
            kk.append(currValue)
        else:
            currValue += len(i)
            kk.append(currValue)
    
    print(max(kk) - min(kk) + 1)
if __name__ == "__main__":
    for i in range(int(input())):
        solve()
