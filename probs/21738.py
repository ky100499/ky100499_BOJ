import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

INF = int(1e9)

N, S, P = map(int, input().split())
G = [{} for _ in range(N+1)]
for _ in range(N-1):
    a, b = map(int, input().split())
    G[a][b] = G[b][a] = 1

dist = [INF]*(N+1)
dist[P] = 0
visited = [0]*(N+1)
q = deque([P])
cnt = 0
ans = 0

while q:
    s = q.popleft()

    if visited[s]:
        continue
    visited[s] = 1

    if s <= S:
        ans += dist[s]
        cnt += 1
        if cnt == 2:
            break
        continue

    for t, d in G[s].items():
        if dist[t] > dist[s]+1:
            dist[t] = dist[s]+1
            q.append(t)

print(N - ans - 1)
