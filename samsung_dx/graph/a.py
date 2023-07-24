def inorder(curr):
    global n, node
    if curr >= n: return
    inorder(curr * 2 + 1)
    print(node[curr], end='')
    inorder(curr * 2 + 2)

def main(tn):
    global n, node
    n = int(input())
    node = ['' for i in range(n)]
    for i in range(n):
        curr, alpha, *sub = input().split()
        node[int(curr) - 1] = alpha
    print(f'#{tn} ')
    inorder(0)
    print('\n')

t = 10

for i in range(1, t + 1):
    main(i)
