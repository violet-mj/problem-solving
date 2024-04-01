import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    h, m = input().split(":")
    h = int(h)

    if h >= 12:
        h -= 12
        if h == 0:
            h = "12"
        elif h < 10:
            h = "0" + str(h)
        else:
            h = str(h)
        return f"{h}:{m} PM"
    else:
        if h == 0:
            h = "12"
        elif h < 10:
            h = "0" + str(h)
        else:
            h = str(h)
        return f"{h}:{m} AM"
if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
