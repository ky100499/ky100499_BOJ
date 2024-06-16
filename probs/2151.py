import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N = int(input())
M = ['']*N
doors = []
for i in range(N):
    for j, c in enumerate(input().rstrip()):
        if c == '#':
            doors.append((i, j))
        M[i] += c

# direction: 0-Up 1-Right 2-Down 3-Left
# (d + (1 or 3)) % 4
mv = [[-1,0], [0,1], [1,0], [0,-1]]

q1 = deque([(0, *doors[0], i) for i in range(4)])
q2 = deque()
visited = [[[0]*4 for _ in range(N)] for _ in range(N)]
while q1 or q2:
    if q1 and (not q2 or q1[0][0] < q2[0][0]):
        m, x, y, d = q1.popleft()
    else:
        m, x, y, d = q2.popleft()

    if not (0 <= x < N and 0 <= y < N):
        continue

    if (x, y) == doors[1]:
        print(m)
        break

    if visited[x][y][d]:
        continue
    visited[x][y][d] = 1

    if M[x][y] != '*':
        q1.append((m, x+mv[d][0], y+mv[d][1], d))
    if M[x][y] == '!':
        for nd in (d+1, d+3):
            nd %= 4
            q2.append((m+1, x+mv[nd][0], y+mv[nd][1], nd))

