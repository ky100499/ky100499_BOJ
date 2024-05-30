import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = 10**8

V, E = map(int, input().split())

dist = [[INF]*(V+1) for _ in range(V+1)]
for _ in range(E):
    a, b, c = map(int, input().split())
    dist[a][b] = c
for i in range(V+1):
    dist[i][i] = 0
for k in range(1, V+1):
    for i in range(1, V+1):
        for j in range(1, V+1):
            dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])

ans = INF
for i in range(1, V+1):
    for j in range(1, V+1):
        if i != j:
            ans = min(ans, dist[i][j]+dist[j][i])
print(-1 if ans == INF else ans)
