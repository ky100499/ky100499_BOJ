import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = int(1e9)

N, M = map(int, input().split())
dist = [[INF]*(N+1) for _ in range(N+1)]
for i in range(1, N+1):
    dist[i][i] = 0

for _ in range(M):
    a, b = map(int, input().split())
    dist[a][b] = 1
    dist[b][a] = -1

for k in range(1, N+1):
    for i in range(1, N+1):
        for j in range(1, N+1):
            if dist[i][j] == INF and dist[i][k] == dist[k][j] != INF:
                dist[i][j] = dist[i][k]

ans = 0
for i in range(1, N+1):
    l, h = dist[i].count(1), dist[i].count(-1)
    ans += l > N//2 or h > N//2
print(ans)
