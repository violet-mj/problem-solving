import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    s = input()
    n = len(s)
    ls = list(s)

    if n == 1:
        if s[0] == '?':
            print('1')
            return 
        else:
            print(s)
            return

    for i in range(n-1,-1,-1):
        if i == 0 and ls[i] == '?':
            ls[i] = '0'
        elif i == n - 1 and ls[i] == '?':
            ls[i] = '1'
        elif ls[i] == '?':
            if ls[i+1] == '0':
                ls[i] = '0'
            else:
                ls[i] = '1'

    print(''.join(ls))
    


    

if __name__ == "__main__":
    for i in range(int(input())):
        solve()
