import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())

    km = []
    r = []
    c = []

    for i in range(6):
        km.append(list(map(int, input().split())))

    for d, dist in km:
        if d in (1, 2):
            r.append(dist)
        else:
            c.append(dist)

    totalWidth = max(r) * max(c)

    if km[0][0] == km[-2][0] and km[1][0] == km[-1][0]:
        totalWidth -= km[0][1] * km[-1][1]
        return totalWidth * n
    
    if km[0][0] == km[2][0] and km[1][0] == km[-1][0]:
        totalWidth -= km[0][1] * km[1][1]
        return totalWidth * n

    if km[-1][0] == km[-3][0] and km[0][0] == km[-2][0]:
        totalWidth -= km[-1][1] * km[-2][1]
        return totalWidth * n

    a = set()

    for idx, info in enumerate(km):
        if info[0] not in a:
            a.add(info[0])
        else:
            result_ = totalWidth - (km[idx][1] * km[idx-1][1]) 
            result_ *= n
            return result_

if __name__ == "__main__":
    print(solve())
