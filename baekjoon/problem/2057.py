import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write


def backtracking(curr, cum):
    global n, fact

    if cum == n:
        print("YES")
        sys.exit(0)
    elif cum > n:
        return
    else:
        for i in range(curr + 1, 20):
            backtracking(i, cum + fact[i])
    

def solve():
    global n, fact
    n = int(input())

    fact = [1]

    for i in range(1, 20):
        fact.append(fact[-1] * i)

    for i in range(20):
        backtracking(i, fact[i])
    
    print("NO")

    

    

if __name__ == "__main__":
    solve()
