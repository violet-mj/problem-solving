import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write
L = set()
for i in range(2, 1000):
    k = 1 + i
    for j in range(2, 60):
        k += i ** j 
        if k <= 10**18:
            L.add(k)
aa = list(L)
aa.sort()
print(aa)

def solve():
    n = int(input())

    if L[n]:
        return "YES"
    
    return "NO"

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
