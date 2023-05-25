import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write


def solve():
    n = int(input())
    s = input()


    maxCount = -1
    count = -1
    for i in s:
        if i == 'o':
            count += 1
        else:
            if count != -1:
                maxCount = max(maxCount, count + 1) 
                count = -1

    count = -1

    for i in s[::-1]:
        if i == 'o':
            count += 1
        else:
            if count != -1:
                maxCount = max(maxCount, count + 1) 
                count = -1

    return maxCount
            



if __name__ == "__main__":
    print(solve())

