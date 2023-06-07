import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    s1 = input()
    s2 = input()

    for i in range(n):
        if s1[i] == s2[i]:
            continue

        if s1[i] == 'o' and s2[i] == '0':
            continue
        if s1[i] == '0' and s2[i] == 'o':
            continue

        if s1[i] == '1' and s2[i] == 'l':
            continue
        if s1[i] == 'l' and s2[i] == '1':
            continue

        return "No"
    
    return "Yes"
    

if __name__ == "__main__":
    print(solve())
