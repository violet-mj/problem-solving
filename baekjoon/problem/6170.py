import sys

for s in sys.stdin:
    if s == '0\n':
        break
    sc = int(s)
    c = 0
    while sc // 10 != 0:
        while sc != 0:
            c += sc % 10
            sc //= 10
        sc = c
        c = 0
    print(sc)
        
