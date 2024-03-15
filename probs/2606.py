import sys
input = sys.stdin.readline

from collections import deque

N = int(input())
edges = [[] for _ in range(N+1)]
for _ in range(int(input())):
    a, b = map(int, input().split())
    edges[a].append(b)
    edges[b].append(a)

q = deque([1])
visited = {}
cnt = 0
while q:
    node = q.popleft()
    if node in visited:
        continue
    visited[node] = 1
    cnt += 1

    for edge in edges[node]:
        if edge not in visited:
            q.append(edge)
print(cnt-1)
