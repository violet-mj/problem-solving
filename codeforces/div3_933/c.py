import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    s = input()
    ss = len(s)

    cnt = 0
    for i in range(ss - 2):
        curr = s[i:i+3]
        if curr in ["map", "pie"]:
            cnt+=1

    for i in range(ss - 4):
        curr = s[i:i+5]
        if curr == "mapie":
            cnt-=1

    print(cnt)

if __name__ == "__main__":
    for i in range(int(input())):
        solve()
