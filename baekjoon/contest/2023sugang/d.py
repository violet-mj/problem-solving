import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n = int(input())
    L = [input() for i in range(n)]
    L.sort(key=lambda x: len(x), reverse=True)
    result = 0
    for i in range(n):
        for j in range(i+1, n):
            for z in range(1, len(L[j]) + 1):
                if L[i][-z:] == L[j][:z]:
                    result += 1
                    break

                if L[j][-z:] == L[i][:z]:
                    result += 1
                    break
    return result


if __name__ == "__main__":
    print(solve())
