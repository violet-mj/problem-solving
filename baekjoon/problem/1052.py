import sys
input = lambda: sys.stdin.readline().rstrip()

def popcount(num):
    return bin(num).count('1')

def solve():
    n, k = map(int, input().split())
    cnt = 0
    flag = False 
    res = -1
    curr1 = popcount(n)

    if curr1 <= k:
        # i = 0
        # while curr1 < k:
        #     if n & (1 << i) == 0:
        #         n += (1 << i)
        #         curr1+=1
        #     i+=1
        # return n
        return 0


    for i in range(31, -1, -1):
        if(not n & (1 << i)): continue
        if(flag): 
            res -= (1 << i)
        else:
            cnt+=1
            if(cnt == k):
                flag = True
                res = (1 << i)

    return -1 if res == -1 else res
if __name__ == "__main__":
    print(solve())
