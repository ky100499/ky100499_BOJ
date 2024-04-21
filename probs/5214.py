import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N, K, M = map(int, input().split())

edges = [[] for _ in range(N+1+M)]

for i in range(M):
    for s in map(int, input().split()):
        edges[s].append(N+1+i)
        edges[N+1+i].append(s)

if N == 1:
    print(1)
else:
    q = deque([(1, 1)])
    visited = [0]*(N+M+1)
    found = False
    while q and not found:
        s, d = q.popleft()
        if visited[s]:
            continue
        visited[s] = 1

        for t in edges[s]:
            if t == N:
                print(d//2+1)
                found = True
                break
            if not visited[t]:
                q.append((t, d+1))
    if not found:
        print(-1)
