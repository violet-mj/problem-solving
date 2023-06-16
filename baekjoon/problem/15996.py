n, k = map(int, input().split())
tmpk = k
count = 0

while k <= n:
    count += n // k
    k *= tmpk

print(count)
