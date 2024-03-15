import sys
input = sys.stdin.readline

from collections import deque

N, M = map(int, input().split())
maze = []
for _ in range(N):
    row = []
    for cell in input().strip():
        row.append(ord(cell) - ord('0'))
    maze.append(row)

q = deque([(0, 0)])
visited = {}
while q:
    i, j = q.popleft()
    if (i, j) == (N-1, M-1):
        print(maze[i][j])
        break
    if (i, j) in visited:
        continue
    visited[(i, j)] = 1
    if i > 0 and maze[i-1][j] == 1:
        maze[i-1][j] = maze[i][j] + 1
        q.append((i-1, j))
    if j > 0 and maze[i][j-1] == 1:
        maze[i][j-1] = maze[i][j] + 1
        q.append((i, j-1))
    if i < N-1 and maze[i+1][j] == 1:
        maze[i+1][j] = maze[i][j] + 1
        q.append((i+1, j))
    if j < M-1 and maze[i][j+1] == 1:
        maze[i][j+1] = maze[i][j] + 1
        q.append((i, j+1))
