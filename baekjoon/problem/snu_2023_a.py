import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
	n, m = map(int, input().split())
	res = 0
	for i in range(n+1):
		res += min(m, m + n - i) + 1
	return res

if __name__ == "__main__":
	print(solve())
