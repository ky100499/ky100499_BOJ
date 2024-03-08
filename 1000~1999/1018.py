import sys
input = sys.stdin.readline

N, M = map(int, input().split())

chk_board = [[(x+y) % 2 for x in range(8)] for y in range(2)]

def row_diff(board, r, c, inverse):
    return sum([board[r][c+i] ^ chk_board[(r+inverse) % 2][i] for i in range(8)])

board = []
for _ in range(N):
    board.append(
        list(map(lambda x: 0 if x == 'B' else 1, list(input().strip())))
    )

ans = N * M
for inv in range(2):
    for r in range(N - 7):
        for c in range(M - 7):
            tmp = 0
            for i in range(8):
                tmp += row_diff(board, r+i, c, inv)
            if ans > tmp:
                ans = tmp

print(ans)
