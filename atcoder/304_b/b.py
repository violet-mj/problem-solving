import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    prefixSum = [0, 3, 4, 8, 9, 14, 23]
    a, b = input().split()
    m = {
        "A": 0,
        "B": 1,
        "C": 2,
        "D": 3,
        "E": 4,
        "F": 5,
        "G": 6,
            }
    maxa = max(m[a], m[b])
    maxb = min(m[a], m[b])

    print(abs(prefixSum[maxb] - prefixSum[maxa]))
    
if __name__ == "__main__":
    solve()
