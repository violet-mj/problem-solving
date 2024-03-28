import sys
input = lambda: sys.stdin.readline().rstrip()

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def fractionSimplify(nume, deno):
    g = gcd(nume, deno)
    nume //= g
    deno //= g
    return (nume, deno)

def fractionAdd(fNume, fDeno, rNume, rDeno):
    gDeno = gcd(fDeno, rDeno)
    cDeno = fDeno * rDeno // gDeno

    fNumeMul = cDeno // fDeno
    rNumeMul = cDeno // rDeno

    fNume *= fNumeMul
    rNume *= rNumeMul

    cNume = fNume + rNume

    return fractionSimplify(cNume, cDeno)
    
def solve():
    s = input()
    ps = s.split(".")[1]
    isCircular = 0
    t = 0; m = 1; v = 0; c = 1
    for i in ps:
        if i == "(": isCircular ^= 1; continue
        if i == ")": break

        if isCircular:
            c *= 10
            v *= 10 
            v += int(i)
        else:
            m *= 10
            t *= 10
            t += int(i)


    if v == 0:
        nume, deno = fractionSimplify(t, m)
        return f"{nume}/{deno}"
    else:
        v = v * c
        c = m * (c - 1) * c
        nume, deno = fractionAdd(t, m, v, c)
        return f"{nume}/{deno}"

if __name__ == "__main__":
    for i in range(int(input())):
        print(solve())
