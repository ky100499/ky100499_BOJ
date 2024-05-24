import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())

edges = [{} for _ in range(N+1)]
for _ in range(M):
    a, b, c = map(int, input().split())
    if b in edges[a]:
        edges[a][b] = min(edges[a][b], c)
    else:
        edges[a][b] = c

INF = 10**8
dist = [INF]*(N+1)
dist[1] = 0
for _ in range(N+1):
    update = False
    for i in range(1, N+1):
        if dist[i] != INF:
            for j, d in edges[i].items():
                if dist[j] > dist[i]+d:
                    update = True
                    dist[j] = dist[i]+d
    if not update:
        break
else:
    print(-1)
    exit(0)
for d in dist[2:]:
    print(-1 if d == INF else d)
