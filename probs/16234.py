import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N, L, R = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]

ans = 0
while True:
    cont = False
    AA = [[0]*N for _ in range(N)]
    visited = [[0]*N for _ in range(N)]
    q1 = deque([(0, 0)])
    while q1:
        i, j = q1.popleft()
        if visited[i][j]:
            continue

        q2 = deque([(i, j)])
        hist = deque()
        s = 0
        while q2:
            x, y = q2.popleft()
            if visited[x][y]:
                continue
            visited[x][y] = 1
            hist.append((x, y))
            s += A[x][y]

            for dx, dy in [[-1,0],[0,-1],[1,0],[0,1]]:
                nx, ny = x+dx, y+dy
                if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny]:
                    if L <= abs(A[x][y] - A[nx][ny]) <= R:
                        q2.append((nx, ny))
                    else:
                        q1.append((nx, ny))

        if len(hist) > 1:
            cont = True
        avg = s // len(hist)
        while hist:
            x, y = hist.popleft()
            AA[x][y] = avg
    A = AA
    if not cont:
        break
    ans += 1
print(ans)
