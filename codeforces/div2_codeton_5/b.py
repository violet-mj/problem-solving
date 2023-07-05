import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))
    result = 0

    if result == k:
        return "Yes"

    for i in A:
        if k | i == k:
            result |= i
            if result == k:
                return "Yes"
        else:
            break

    for i in B:
        if k | i == k:
            result |= i
            if result == k:
                return "Yes"
        else:
            break

    for i in C:
        if k | i == k:
            result |= i
            if result == k:
                return "Yes"
        else:
            break

    return "No"



if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
