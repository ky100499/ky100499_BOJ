import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def dfs(i, j, depth):
    global ans
    ans = max(ans, depth)
    visited[board[i][j]] = 1
    for di, dj in [[-1, 0], [0, -1], [1, 0], [0, 1]]:
        ni, nj = i+di, j+dj
        if 0 <= ni < R and 0 <= nj < C and not visited[board[ni][nj]]:
            dfs(ni, nj, depth+1)
    visited[board[i][j]] = 0

R, C = map(int, input().split())
board = []
for _ in range(R):
    board.append(list(map(lambda x: ord(x) - ord('A'), input().strip())))
ans = 0
visited = [0]*26
dfs(0, 0, 1)
print(ans)
