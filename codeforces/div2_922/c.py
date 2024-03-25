import sys
input = lambda: sys.stdin.readline().rstrip()
t = int(input())



for i in range(t):
    a, b, r = map(int, input().split())
    xor = a ^ b
    aa = xor & a
    bb = xor & b
    cnt = 0

    for i in range(1, 61):
        if r >= (1 << i) - 1:
            cnt = (1 << i) - 1
        else:
            break

    maxv = max(aa, bb)
    minv = min(aa, bb)

    diff = maxv & cnt

    print(maxv - minv - 2 * diff)
