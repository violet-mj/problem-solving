import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, k = map(int, input().split())
    fibo = [1, 1]

    for i in range(2, 100001):
        tmp = fibo[i-1] + fibo[i-2]
        fibo.append(tmp)
        if tmp > 10 ** 9: break

    lenf = len(fibo)

    if k - 2 >= lenf:
        return 0

    a = fibo[k - 3]
    b = fibo[k - 2]
    cnt = 0

    for i in range(200001):
        kk = (n - a * i) / b
        kki = int(kk)
        if i > kk: break
        if kk == kki:
            cnt += 1

    return cnt

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
