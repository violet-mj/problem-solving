import sys
input = lambda: sys.stdin.readline().rstrip()

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def addDividing(a1, a2, b1, b2):
    gg = gcd(a2, b2)
    lg = a2 * b2 // gg

    am = lg // a2
    bm = lg // b2

    a1 *= am
    b1 *= bm

    up = a1 + b1
    gud = gcd(up, lg)

    return (up // gud, lg // gud)
    
def solve():
    s = input()
    ps = s.split(".")[1]
    flag = 0

    curr = 0
    currCheck = 1
    check = 1
    
    it = 0

    itr = 1
    
    for i in ps:
        if i == "(": flag ^= 1; continue
        if i == ")": break

        if flag:
            check *= 10
            it *= 10 
            it += int(i)
        else:
            currCheck *= 10
            curr *= 10
            curr += int(i)

    if it == 0:
        gg = gcd(curr, currCheck)
        curr //= gg
        currCheck //= gg
        return f"{curr}/{currCheck}"
    else:
        it *= check
        check *= (check - 1) 
        check *= currCheck

        up, lg = addDividing(curr, currCheck, it, check)

        return f"{up}/{lg}"

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
