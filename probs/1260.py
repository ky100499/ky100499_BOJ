import sys
input = sys.stdin.readline

from collections import deque

def dfs(node, visited):
    if node in visited:
        return
    visited[node] = 1
    print(node, end=' ')
    for edge in edges[node]:
        if edge not in visited:
            dfs(edge, visited)

N, M, V = map(int, input().split())

edges = [set() for _ in range(N+1)]
for _ in range(M):
    a, b = map(int, input().split())
    edges[a].add(b)
    edges[b].add(a)
edges = list(map(sorted, map(list, edges)))

dfs(V, {})
print()

visited = {}
bfs = deque([V])
while bfs:
    node = bfs.popleft()
    if node in visited: continue
    visited[node] = 1
    print(node, end=' ')
    for edge in edges[node]:
        if edge not in visited:
            bfs.append(edge)
print()
