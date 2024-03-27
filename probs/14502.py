import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

def bfs(b):
    for i, j in [(i, j) for i in range(N) for j in range(M)]:
        if b[i][j] == 2:
            q = deque([(i, j)])
            while q:
                x, y = q.popleft()
                if b[x][y] == 3:
                    continue
                b[x][y] = 3
                for dx, dy in [[-1,0],[0,-1],[1,0],[0,1]]:
                    nx, ny = x+dx, y+dy
                    if 0 <= nx < N and 0 <= ny < M and b[nx][ny] == 0:
                        q.append((nx, ny))
    return sum(map(lambda x: x.count(0), b))

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

ans = 0
for i in range(M*N):
    if board[i // M][i % M] != 0:
        continue
    board[i // M][i % M] = 1

    for j in range(i+1, M*N):
        if board[j // M][j % M] != 0:
            continue
        board[j // M][j % M] = 1

        for k in range(j+1, M*N):
            if board[k // M][k % M] != 0:
                continue
            board[k // M][k % M] = 1

            ans = max(bfs(list(map(lambda x: x[:], board))), ans)

            board[k // M][k % M] = 0
        board[j // M][j % M] = 0
    board[i // M][i % M] = 0
print(ans)
