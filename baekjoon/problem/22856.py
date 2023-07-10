import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    global n, tree, count
    n = int(input())
    tree = [[-1 for i in range(2)] for i in range(n + 1)]

    for i in range(n-1):
        a, b, c = map(int, input().split())

        tree[a][0] = b
        tree[a][1] = c

    currNode = 1
    count = 0

    while tree[currNode][1] != -1:
        currNode = tree[currNode][1]
        count += 1

    return 2 * (n - 1) - count


if __name__ == "__main__":
    print(solve())
