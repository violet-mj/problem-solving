n = int(input())
a,b,c,d = map(int, input().split())

if a * n + b == c * n + d:
    print("Yes", a * n + b)
else:
    print("No")
