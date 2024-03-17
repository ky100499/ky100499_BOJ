import sys
input = sys.stdin.readline

from collections import deque

N = int(input())
mat = []
for _ in range(N):
    mat.append(list(map(int, input().split())))

connected = [set() for _ in range(N)]
for i in range(N):
    for j, v in enumerate(mat[i]):
        if v:
            connected[i].add(j)

ans = [[0]*N for _ in range(N)]
for i in range(N):
    q = deque([i])
    while q:
        node = q.popleft()
        for con in connected[node]:
            if ans[i][con] == 0:
                ans[i][con] = 1
                q.append(con)

for row in ans:
    print(' '.join(map(str, row)))
