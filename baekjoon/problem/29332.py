import sys
input = lambda: sys.stdin.readline().rstrip()
INF = sys.maxsize
def solve():
	n = int(input())

	l,r,b,u = -INF, INF, -INF, INF
	
	
	for i in range(n):
		xi, yi, dir = input().split()
		xi, yi = int(xi), int(yi)

		if dir == "L":
			r = min(xi, r)
		elif dir == "R":
			l = max(xi, l)
		elif dir == "D":
			u = min(yi, u)
		else:
			b = max(yi, b)
	
	if l == -INF or r == INF or b == -INF or u == INF:
		print("Infinity")
	else:
		print((r - l - 1) * (u - b - 1))				

if __name__ == "__main__":
	solve()
