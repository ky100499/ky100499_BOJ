import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N, M = map(int, input().split())
con = [[] for _ in range(N+1)]
for _ in range(M):
    u, v = map(int, input().split())
    con[u].append(v)
    con[v].append(u)

visited = {}
cnt = 0
for i in range(1, N+1):
    if i in visited:
        continue
    visited[i] = 1

    cnt += 1
    q = deque([i])
    while q:
        node = q.popleft()
        for edge in con[node]:
            if edge not in visited:
                visited[edge] = 1
                q.append(edge)

print(cnt)
