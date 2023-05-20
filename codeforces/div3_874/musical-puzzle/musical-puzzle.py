import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write
 
def solve():
    n = int(input())
    s = input()
    store = set()
    count = 0
    for i in range(len(s) - 1):
        if s[i:i+2] not in store:
            store.add(s[i:i+2])
            count += 1
 
    return count
 
 
if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
