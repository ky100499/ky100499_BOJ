import sys
input = sys.stdin.readline

from collections import deque

N, M = map(int, input().split())
edges = [set() for _ in range(N+1)]
for _ in range(M):
    a, b = map(int, input().split())
    edges[a].add(b)
    edges[b].add(a)

min_bacon = 1000000
ans = 0
for i in range(1, N+1):
    bfs = deque((edge, 1) for edge in edges[i])
    visited = {}
    bacon = 0

    while bfs:
        node, n = bfs.popleft()
        if node in visited:
            continue
        visited[node] = 1

        bacon += n
        for edge in edges[node]:
            if edge not in visited:
                bfs.append((edge, n+1))

    if bacon < min_bacon:
        min_bacon = bacon
        ans = i

print(ans)
