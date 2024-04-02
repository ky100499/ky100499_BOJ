import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N, M = map(int, input().split())
cheese = [list(map(int, input().split())) for _ in range(N)]
cnt = sum(map(lambda x: x.count(1), cheese))

ans = 0
while cnt:
    airs = [[0]*M for _ in range(N)]
    q = deque([(0, 0)])
    visited = set()
    while q:
        i, j = q.popleft()

        if (i, j) in visited:
            continue
        visited.add((i, j))

        for di, dj in [[-1,0],[0,-1],[1,0],[0,1]]:
            ni, nj = i+di, j+dj
            if 0 <= ni < N and 0 <= nj < M:
                airs[ni][nj] += 1
                if (ni, nj) not in visited and cheese[ni][nj] == 0:
                    q.append((ni, nj))

    for i in range(N):
        for j in range(M):
            if cheese[i][j] == 1 and airs[i][j] >= 2:
                cheese[i][j] = 0
                cnt -= 1

    ans += 1

print(ans)
