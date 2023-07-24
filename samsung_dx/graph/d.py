import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def dfs(currNode, currLevel):
    global v, e, level, tree, rTree, dp
    level[currNode] = currLevel

    if ~dp[currNode]: dp[currNode]
    if not len(tree[currNode]): 
        dp[currNode] = 1
        return 1
    
    tmp = 0
    
    for nextNode in tree[currNode]:
        tmp += dfs(nextNode, currLevel + 1)

    dp[currNode] = tmp + 1
    return dp[currNode]


def solve(tn):
    global v, e, level, tree, rTree, dp
    v, e, l, r = map(int, input().split())

    level = [0 for i in range(v + 1)]
    tree = [[] for i in range(v + 1)]
    rTree = [0 for i in range(v + 1)]
    dp = [-1 for i in range(v + 1)]

    L = list(map(int, input().split()))

    for i in range(0, 2 * e, 2):
        parent = L[i]
        child = L[i + 1]
        tree[parent].append(child)
        rTree[child] = parent

    dfs(1, 1)

    if(l == 1 or r == 1):
        print(f'#{tn+1} {1} {dp[1]}')
        return


    if(level[l] > level[r]):
        l, r = r, l

    while(level[l] != level[r]):
        r = rTree[r]

    while(l != r):
        l = rTree[l]
        r = rTree[r]
    
    print(f'#{tn+1} {l} {dp[l]}')
        
if __name__ == "__main__":
    for i in range(int(input())):
        solve(i)
