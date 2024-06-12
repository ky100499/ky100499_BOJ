import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N, Q = map(int, input().split())
edges = [{} for _ in range(N+1)]
for _ in range(N-1):
    p, q, r = map(int, input().split())
    edges[p][q] = r
    edges[q][p] = r

for _ in range(Q):
    k, v = map(int, input().split())

    ans = 0
    visited = [0]*(N+1)
    visited[v] = 1
    q = deque([v])
    while q:
        v = q.popleft()

        for n, r in edges[v].items():
            if r >= k and not visited[n]:
                visited[n] = 1
                ans += 1
                q.append(n)

    print(ans)
