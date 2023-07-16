import sys
input = lambda: sys.stdin.readline().rstrip()
output = sys.stdout.write

def solve():
    n, m = map(int, input().split())
    board = []

    for i in range(n):
        p, fc, *f = map(int, input().split())
        board.append((p, set(f)))

    for i in range(n):
        for j in range(i+1, n):
            if board[i][0] == board[j][0]:
                if len(board[i][1] - board[j][1]) == 0 and len(board[i][1]) < len(board[j][1]):
                    return "Yes"
                continue
            if board[i][0] > board[j][0]:
                if len(board[i][1] - board[j][1]) == 0:
                    return "Yes"
            else:
                if len(board[j][1] - board[i][1]) == 0:
                    return "Yes"
    
    return "No"

if __name__ == "__main__":
    print(solve())
