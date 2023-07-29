import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n, m = map(int, input().split())
    s = input() 
    query = []
    set_ = set()

    prefixSum = [0]

    curr0 = [-1 for i in range(n)]
    c0 = -1
    for idx, i in enumerate(s):
        if i == '0':
            curr0[idx] = idx
            c0 = idx
        else:
            curr0[idx] = c0





    for i in range(n):
        prefixSum.append(prefixSum[-1] + int(s[i]))
    print(prefixSum)
    flag = False
    
    for i in range(m):
        a, b = map(int, input().split())
        latest0 = curr0[b-1] + 1

        if latest0 < a:
            continue

        value = prefixSum[latest0] - prefixSum[a-1]
        set_.add((latest0, value))

    return len(set_)

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
